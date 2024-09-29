#pragma once

#include <DirectXMath.h>

class Transform
{
private: 
	DirectX::XMFLOAT3 position;
	DirectX::XMFLOAT3 rotation;
	DirectX::XMFLOAT3 scale;

	DirectX::XMFLOAT4X4 world;
	DirectX::XMFLOAT4X4 worldInverseTranspose;

public:
	Transform();

	//setters
	void SetPosition(float x, float y, float z);
	void SetPosition(DirectX::XMFLOAT3 pos);

	void SetRotation(float p, float y, float r);
	void SetRotation(DirectX::XMFLOAT3 rot);

	void SetScale(float sx, float sy, float sz);
	void SetScale(DirectX::XMFLOAT3 sc);

	//getters
	DirectX::XMFLOAT3 GetPosition();
	DirectX::XMFLOAT3 GetPitchYawRoll();
	DirectX::XMFLOAT3 GetScale();
	DirectX::XMFLOAT4X4 GetWorldMatrix();
	DirectX::XMFLOAT4X4 GetWorldInverseTransposeMatrix();

	//transformers
	void MoveAbsolute(float x, float y, float z);
	void MoveAbsolute(DirectX::XMFLOAT3 offset);

	void Rotate(float p, float y, float r);
	void Rotate(DirectX::XMFLOAT3 rot);

	void Scale(float sx, float sy, float sz);
	void Scale(float sc);
};

