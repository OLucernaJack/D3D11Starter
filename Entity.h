#pragma once

#include "Mesh.h"
#include "Transform.h"
#include <memory>
#include <wrl/client.h>

class Entity
{
private:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Transform> transform;

public:
	Entity(std::shared_ptr<Mesh> mesh);

	//getters
	std::shared_ptr<Mesh> GetMesh();
	std::shared_ptr<Transform> GetTransform();

	//drawing
	void Draw(Microsoft::WRL::ComPtr<ID3D11Buffer> vsConstantBuffer);
};

