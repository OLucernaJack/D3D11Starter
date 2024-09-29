#include "Transform.h"

#include <DirectXMath.h>

using namespace DirectX;

Transform::Transform() :
    position(0, 0, 0),
    rotation(0, 0, 0),
    scale(1, 1, 1)
{
    XMStoreFloat4x4(&world, XMMatrixIdentity());
    XMStoreFloat4x4(&worldInverseTranspose, XMMatrixIdentity());
}

void Transform::SetPosition(float x, float y, float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Transform::SetPosition(DirectX::XMFLOAT3 pos)
{
    this->position = pos;
}

void Transform::SetRotation(float p, float y, float r)
{
    rotation.x = p;
    rotation.y = y;
    rotation.z = r;
}

void Transform::SetRotation(DirectX::XMFLOAT3 rot)
{
    this->rotation = rot;
}

void Transform::SetScale(float sx, float sy, float sz)
{
    scale.x = sx;
    scale.y = sy;
    scale.z = sz;
}

void Transform::SetScale(DirectX::XMFLOAT3 sc)
{
    this->scale = sc;
}

DirectX::XMFLOAT3 Transform::GetPosition()
{
    return position;
}

DirectX::XMFLOAT3 Transform::GetPitchYawRoll()
{
    return rotation;
}

DirectX::XMFLOAT3 Transform::GetScale()
{
    return scale;
}

DirectX::XMFLOAT4X4 Transform::GetWorldMatrix()
{
    XMVECTOR pos = XMLoadFloat3(&position);
    XMMATRIX transMat = XMMatrixTranslationFromVector(pos);

    XMVECTOR rot = XMLoadFloat3(&rotation);
    XMMATRIX rotMat = XMMatrixRotationRollPitchYawFromVector(rot);

    XMVECTOR sc = XMLoadFloat3(&scale);
    XMMATRIX scMat = XMMatrixScalingFromVector(sc);

    XMMATRIX worldMat = XMMatrixMultiply(XMMatrixMultiply(scMat, rotMat), transMat);

    XMStoreFloat4x4(&world, worldMat);
    XMStoreFloat4x4(&worldInverseTranspose, XMMatrixInverse(0, XMMatrixTranspose(worldMat)));

    return world;
}

DirectX::XMFLOAT4X4 Transform::GetWorldInverseTransposeMatrix()
{
    return worldInverseTranspose;
}

void Transform::MoveAbsolute(float x, float y, float z)
{
    position.x += x;
    position.y += y;
    position.z += z;
}

void Transform::MoveAbsolute(DirectX::XMFLOAT3 offset)
{
    MoveAbsolute(offset.x, offset.y, offset.z);
}

void Transform::Rotate(float p, float y, float r)
{
    rotation.x += p;
    rotation.y += y;
    rotation.z += r;
}

void Transform::Rotate(DirectX::XMFLOAT3 rot)
{
    Rotate(rot.x, rot.y, rot.z);
}

void Transform::Scale(float sx, float sy, float sz)
{
    scale.x *= sx;
    scale.y *= sy;
    scale.z *= sz;
}

void Transform::Scale(float sc)
{
    Scale(sc, sc, sc);
}
