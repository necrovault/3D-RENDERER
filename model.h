#pragma once
#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stb/stb_image.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "mesh.h"
#include "shader.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma);

class Model
{
public:
	// model data
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	bool gammaCorrection;

	// constructor, expects a filepath to a 3D model
	Model(std::string const& path, bool gamma);

	// droaw the mode, and thus all its meshes
	void Draw(Shader& shader);

private:
	// loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector
	void loadModel(std::string const& path);
	
	// processes a node in a recursive fashion
	void processNode(aiNode* node, const aiScene* scene);

	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

	// checks all the material textures of a given type and loads the textures if they're not loaded yet
	// the required info is returned as a Texture struct
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
};

