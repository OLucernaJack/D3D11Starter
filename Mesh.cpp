#include "Mesh.h"
#include "Graphics.h"
#include "Vertex.h"


//constructor
Mesh::Mesh(Vertex* vertices, unsigned int* indices, size_t _indiceCount, size_t _verticeCount) {
	//save count info
	this->verticeCount = _verticeCount;
	this->indiceCount = _indiceCount;
	
	
	//Below code copied from Game::CreateGeometry and adjusted
	{
		D3D11_BUFFER_DESC vbd = {};
		vbd.Usage = D3D11_USAGE_IMMUTABLE;
		vbd.ByteWidth = sizeof(Vertex) * _verticeCount;
		vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vbd.CPUAccessFlags = 0;
		vbd.MiscFlags = 0;
		vbd.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initialVertexData = {};
		initialVertexData.pSysMem = vertices; //pass in vertex array

		Graphics::Device->CreateBuffer(&vbd, &initialVertexData, vertexBfr.GetAddressOf());
	}

	{
		D3D11_BUFFER_DESC ibd = {};
		ibd.Usage = D3D11_USAGE_IMMUTABLE;	
		ibd.ByteWidth = sizeof(unsigned int) * _indiceCount;	
		ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;	
		ibd.CPUAccessFlags = 0;	
		ibd.MiscFlags = 0;
		ibd.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initialIndexData = {};
		initialIndexData.pSysMem = indices; // pass in indice array

		Graphics::Device->CreateBuffer(&ibd, &initialIndexData, indexBfr.GetAddressOf());
	}

	
}

//destructor
Mesh::~Mesh() {}

//vertex buffer access
Microsoft::WRL::ComPtr<ID3D11Buffer> Mesh::GetVertexBuffer()
{
	return vertexBfr;
}

//index buffer access
Microsoft::WRL::ComPtr<ID3D11Buffer> Mesh::GetIndexBuffer() {
	return indexBfr;
}

//vertex size access
int Mesh::GetVertexCount() {
	return verticeCount;
}

//index size access
int Mesh::GetIndexCount() {
	return indiceCount;
}

//drawing
void Mesh::Draw() {
	//Below code copied and changed from Game::Draw()
	//set up
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	Graphics::Context->IASetVertexBuffers(0, 1, vertexBfr.GetAddressOf(), &stride, &offset);
	Graphics::Context->IASetIndexBuffer(indexBfr.Get(), DXGI_FORMAT_R32_UINT, 0);

	//draw
	Graphics::Context->DrawIndexed(
		indiceCount,     
		0,     
		0);
}