#include "soh/resource/importer/BackgroundFactory.h"
#include "soh/resource/type/Background.h"
#include "spdlog/spdlog.h"

namespace LUS {
std::shared_ptr<IResource> BackgroundFactory::ReadResource(std::shared_ptr<ResourceInitData> initData,
                                                           std::shared_ptr<BinaryReader>     reader) {
    auto                                    resource = std::make_shared<Background>(initData);
    std::shared_ptr<ResourceVersionFactory> factory = nullptr;

    switch (resource->GetInitData()->ResourceVersion) {
        case 0:
            factory = std::make_shared<BackgroundFactoryV0>();
            break;
    }

    if (factory == nullptr) {
        SPDLOG_ERROR("Failed to load Background with version {}", resource->GetInitData()->ResourceVersion);
        return nullptr;
    }

    factory->ParseFileBinary(reader, resource);

    return resource;
}

void BackgroundFactoryV0::ParseFileBinary(std::shared_ptr<BinaryReader> reader, std::shared_ptr<IResource> resource) {
    std::shared_ptr<Background> background = std::static_pointer_cast<Background>(resource);
    ResourceVersionFactory::ParseFileBinary(reader, background);

    uint32_t dataSize = reader->ReadUInt32();

    background->Data.reserve(dataSize);

    for (uint32_t i = 0; i < dataSize; i++) {
        background->Data.push_back(reader->ReadUByte());
    }
}
} // namespace LUS
