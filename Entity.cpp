#include "Entity.h"
#include "BufferStructs.h"
#include "Graphics.h"

using namespace DirectX;

Entity::Entity(std::shared_ptr<Mesh> mesh)
{
    this->mesh = mesh;
    transform = std::make_shared<Transform>();
}

std::shared_ptr<Mesh> Entity::GetMesh()
{
    return mesh;
}

std::shared_ptr<Transform> Entity::GetTransform()
{
    return transform;
}

void Entity::Draw(Microsoft::WRL::ComPtr<ID3D11Buffer> vsConstantBuffer)
{
    VertexShaderData vsData;
    vsData.colorTint = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
    vsData.worldMatrix = transform->GetWorldMatrix();

    D3D11_MAPPED_SUBRESOURCE mappedBuffer = {};
    Graphics::Context->Map(vsConstantBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedBuffer);

    memcpy(mappedBuffer.pData, &vsData, sizeof(vsData));

    Graphics::Context->Unmap(vsConstantBuffer.Get(), 0);

    mesh->Draw();
}
