#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Shader.h"

class Application :
    public RenderEngine
{
public:
    Application();
    ~Application();
private:
	Shader *shader;
	Cube* cube; 
	float angle;
	glm::vec3 viewPos;
	void setupPerspective();
	void setupCamera();
	void setupLighting(); 
	virtual void Init();
	virtual void DeInit(); 
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);
};

