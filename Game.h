#pragma once

#include <d3d11.h>
#include <wrl/client.h>

#include <memory>
#include <vector>
#include "Mesh.h"
#include "BufferStructs.h"

class Game
{
public:
	// Basic OOP setup
	Game() = default;
	~Game();
	Game(const Game&) = delete; // Remove copy constructor
	Game& operator=(const Game&) = delete; // Remove copy-assignment operator

	// Primary functions
	void Initialize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);
	void OnResize();

private:

	// Initialization helper methods - feel free to customize, combine, remove, etc.
	void LoadShaders();
	void CreateGeometry();

	//ui info
	bool isDemoWindowOn;
	float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	int number;

	//store all meshes here
	std::vector<std::shared_ptr<Mesh>> meshes;
	std::shared_ptr<Mesh> triangle;
	std::shared_ptr<Mesh> square;
	std::shared_ptr<Mesh> pentagon;

	//vsData here
	VertexShaderData vsData;

	// Note the usage of ComPtr below
	//  - This is a smart pointer for objects that abide by the
	//     Component Object Model, which DirectX objects do
	//  - More info here: https://github.com/Microsoft/DirectXTK/wiki/ComPtr

	// Buffers to hold actual geometry data
	//Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	//Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> vsConstBuffer;

	// Shaders and shader-related constructs
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
};

