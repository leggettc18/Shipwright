// Feature to mark an entrance in-game so that you can tell
// whether you have traversed it or not. Useful in decoupled
// entrance randomizers

#include "soh/Enhancements/game-interactor/GameInteractor_Hooks.h"
#include "soh/ShipInit.hpp"
#include "../frame_interpolation.h"
extern "C" {
#include <macros.h>
#include <variables.h>
#include <functions.h>
extern PlayState* gPlayState;
}

static std::vector<Gfx> xluDl;
static std::vector<Vtx> vtxDl;
#define G_CC_PRIMITIVE_ENVA 0, 0, 0, PRIMITIVE, 0, 0, 0, ENVIRONMENT
#define qs105(n) ((int16_t)((n)*0x0020))
#define gdSPDefVtxN(x, y, z, s, t, nx, ny, nz, ca)                                            \
    {                                                                                         \
        .n = {.ob = { x, y, z }, .tc = { qs105(s), qs105(t) }, .n = { nx, ny, nz }, .a = ca } \
    }

void InitGfx(std::vector<Gfx>& gfx) {
    uint32_t rm;
    uint32_t blc1;
    uint32_t blc2;
    uint8_t alpha;
    uint64_t cm;
    uint32_t gm;
    rm = Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_DEC;
    blc1 = GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA);
    blc2 = GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA);
    alpha = 0x80;
    gfx.push_back(gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF));
    gfx.push_back(gsDPSetCycleType(G_CYC_1CYCLE));
    gfx.push_back(gsDPSetRenderMode(rm | blc1, rm | blc2));
    gfx.push_back(gsDPSetCombineMode(G_CC_PRIMITIVE_ENVA, G_CC_PRIMITIVE_ENVA));
    gfx.push_back(gsSPLoadGeometryMode(G_ZBUFFER));
    gfx.push_back(gsDPSetEnvColor(0xFF, 0xFF, 0xFF, alpha));
}

void DrawEntrancePoly(std::vector<Gfx>& dl, CollisionHeader* col, int32_t bgId) {
    Color_RGBA8 color = {255, 255, 255, 255};
    uint32_t lastColorR = color.r;
    uint32_t lastColorG = color.g;
    uint32_t lastColorB = color.b;

    dl.push_back(gsDPSetPrimColor(0, 0, color.r, color.g, color.b, 255));
    bool previousPoly = false;
    for (int i = 0; i < col->numPolygons; i++) {
        CollisionPoly* poly = &col->polyList[i];
        if (SurfaceType_GetSceneExitIndex(&gPlayState->colCtx, poly, bgId) ||
            func_80041E80(&gPlayState->colCtx, poly, bgId) == 0x05) {
                // TODO: Check if entrance has been traversed before and draw different colors
                color = CVarGetColor(CVAR_DEVELOPER_TOOLS("ColViewer.ColorEntrance"), {0, 255, 0, 255});
                if (color.r != lastColorR || color.g != lastColorG || color.b != lastColorB) {
                    if (previousPoly) {
                        dl.push_back(gsSPVertex((uintptr_t)&vtxDl.at(vtxDl.size() -3), 3, 0));
                        dl.push_back(gsSP1Triangle(0, 1, 2, 0));
                        previousPoly = false;
                    }
                    dl.push_back(gsDPSetPrimColor(0, 0, color.r, color.g, color.b, 255));
                }
                lastColorR = color.r;
                lastColorG = color.g;
                lastColorB = color.b;

                Vec3s* va = &col->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIA)];
                Vec3s* vb = &col->vtxList[COLPOLY_VTX_INDEX(poly->flags_vIB)];
                Vec3s* vc = &col->vtxList[COLPOLY_VTX_INDEX(poly->vIC)];
                vtxDl.push_back(gdSPDefVtxN(va->x, va->y, va->z, 0, 0, (signed char)(poly->normal.x / 0x100),
                                            (signed char)(poly->normal.y / 0x100),
                                            (signed char)(poly->normal.z / 0x100), 0xFF));
                vtxDl.push_back(gdSPDefVtxN(vb->x, vb->y, vb->z, 0, 0, (signed char)(poly->normal.x / 0x100),
                                            (signed char)(poly->normal.y / 0x100),
                                            (signed char)(poly->normal.z / 0x100), 0xFF));
                vtxDl.push_back(gdSPDefVtxN(vc->x, vc->y, vc->z, 0, 0, (signed char)(poly->normal.x / 0x100),
                                            (signed char)(poly->normal.y / 0x100),
                                            (signed char)(poly->normal.z / 0x100), 0xFF));

                if (previousPoly) {
                    dl.push_back(gsSPVertex((uintptr_t)&vtxDl.at(vtxDl.size() - 6), 6, 0));
                    dl.push_back(gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0));
                    previousPoly = false;
                } else {
                    previousPoly = true;
                }
            }
    }
}

template <typename T> size_t ResetVector(T& vec) {
    size_t oldSize = vec.size();
    vec.clear();
    vec.reserve(oldSize * 1.2);
    return vec.capacity();
}

void DrawEntranceCollision() {
    std::vector<Gfx>& dl = xluDl;
    InitGfx(dl);
    dl.push_back(gsSPMatrix(&gMtxClear, G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH));
    DrawEntrancePoly(dl, gPlayState->colCtx.colHeader, BGCHECK_SCENE);
}

void DrawEntranceIndicators() {
    if (gPlayState == nullptr) {
        return;
    }
    ResetVector(xluDl);
    size_t vtxDlCapacity = ResetVector(vtxDl);
    DrawEntranceCollision();
    if (vtxDl.size() > vtxDlCapacity) {
        ResetVector(xluDl);
        vtxDlCapacity = ResetVector(vtxDl);
    }
    if (vtxDl.size() > vtxDlCapacity) {
        // If the sizes somehow changed between the two draws, we can't continue because we may be using invalid data
        printf("Error drawing collision, vertex/matrix sizes didn't settle.\n");
        return;
    }
    OPEN_DISPS(gPlayState->state.gfxCtx);
    uint8_t mirroredWorld = CVarGetInteger(CVAR_ENHANCEMENT("MirroredWorld"), 0);
    if (mirroredWorld) {
        gSPSetExtraGeometryMode(POLY_XLU_DISP++, G_EX_INVERT_CULLING);
    }
    xluDl.push_back(gsSPEndDisplayList());
    gSPDisplayList(POLY_XLU_DISP++, xluDl.data());
    CLOSE_DISPS(gPlayState->state.gfxCtx);
}

#define CVAR_ENTRANCEINDICATORS_NAME CVAR_ENHANCEMENT("EntranceIndicators")
#define CVAR_ENTRANCEINDICATORS_DEFAULT 0
#define CVAR_ENTRANCEINDICATORS_VALUE CVarGetInteger(CVAR_ENTRANCEINDICATORS_NAME, CVAR_ENTRANCEINDICATORS_DEFAULT)

void RegisterEntranceIndicators() {
    COND_HOOK(OnPlayDrawEnd, CVAR_ENTRANCEINDICATORS_VALUE != CVAR_ENTRANCEINDICATORS_DEFAULT, DrawEntranceIndicators);
}

static RegisterShipInitFunc initFunc(RegisterEntranceIndicators, { CVAR_ENTRANCEINDICATORS_NAME });