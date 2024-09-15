#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include "Vertex.h"

class Mesh
{
private:
	//get two cmptr
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBfr;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBfr;

	//integer of how many indices
	int indiceCount;

	//iteger of how many vertices
	int verticeCount;

	//other useful data?

public:
	//get vertex buffer
	Microsoft::WRL::ComPtr<ID3D11Buffer> GetVertexBuffer();
	//get index buffer
	Microsoft::WRL::ComPtr<ID3D11Buffer> GetIndexBuffer();

	//get index count
	int GetIndexCount();
	//get vertex count
	int GetVertexCount();

	//set buffer, draws
	void Draw();

	//constructor
	Mesh(Vertex* vertices, unsigned int* indices, size_t _indiceCount, size_t _verticeCount);
	//destructor
	~Mesh();
};

