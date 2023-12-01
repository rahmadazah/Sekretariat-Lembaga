#include "Application.h"

Application::Application()
{
	angle = 0;
}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(0, 1, 5);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(1, 0, 0), glm::vec3(0, 2, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3( 4, 4, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("cube.vert", "cube.frag");
	shader->Init();
	// Create instance of cube
	cube = new Cube(shader);
	cube->Init();
	cube->SetRotation(0, 0, 1, 0);
	
	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	angle += (float)((deltaTime * 0.5f) / 1000);
	cube->SetRotation(angle, 0, 1, 0);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetBackgroundColor(94, 232, 247);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	//rak
	// Bagian bawah
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(0.0f, 0.0f, 0.0f);
	cube->SetScale(0.5f, 0.1f, 0.5f);
	cube->Draw();
	// Bagian tengah bawah
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(0.0f, 0.4f, 0.0f);
	cube->SetScale(0.5f, 0.1f, 0.5f);
	cube->Draw();
	// Bagian tengah atas
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(0.0f, 0.8f, 0.0f);
	cube->SetScale(0.5f, 0.1f, 0.5f);
	cube->Draw();
	// Bagian atas
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(0.0f, 1.2f, 0.0f);
	cube->SetScale(0.5f, 0.1f, 0.5f);
	cube->Draw();
	//Bagian samping kanan
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(0.25f, 0.6f, 0.0f);
	cube->SetScale(0.1f, 1.2f, 0.5f);
	cube->Draw();
	//Bagian samping kiri
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(-0.25f, 0.6f, 0.0f);
	cube->SetScale(0.1f, 1.2f, 0.5f);
	cube->Draw();

	//buku di rak tengah 
	//Buku 1 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(-0.175f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 2 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(-0.125f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 3 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(-0.075f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 4 tes
	cube->SetColor(240.0f, 75.0f, 235.0f);
	cube->SetPosition(-0.025f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 5 tes
	cube->SetColor(39.0f, 25.0f, 210.0f);
	cube->SetPosition(0.025f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 6 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(0.075f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 7 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(0.125f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 8 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(0.175f, 0.6f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();

	//buku di rak bawah 
	//Buku 1 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(-0.175f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 2 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(-0.125f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 3 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(-0.075f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 4 tes
	cube->SetColor(240.0f, 75.0f, 235.0f);
	cube->SetPosition(-0.025f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 5 tes
	cube->SetColor(39.0f, 25.0f, 210.0f);
	cube->SetPosition(0.025f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 6 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(0.075f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 7 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(0.125f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 8 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(0.175f, 0.2f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();

	//buku di rak atas 
	//Buku 1 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(-0.175f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 2 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(-0.125f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 3 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(-0.075f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 4 tes
	cube->SetColor(240.0f, 75.0f, 235.0f);
	cube->SetPosition(-0.025f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 5 tes
	cube->SetColor(39.0f, 25.0f, 210.0f);
	cube->SetPosition(0.025f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 6 tes
	cube->SetColor(77.0f, 215.0f, 50.0f);
	cube->SetPosition(0.075f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 7 tes
	cube->SetColor(157.0f, 5.0f, 127.0f);
	cube->SetPosition(0.125f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();
	//Buku 8 tes
	cube->SetColor(237.0f, 25.0f, 140.0f);
	cube->SetPosition(0.175f, 1.0f, 0.0f);
	cube->SetScale(0.05f, 0.3f, 0.35f);
	cube->Draw();

	//meja kiri
	//Bagian atas
	cube->SetColor(117.0f, 69.0f, 12.0f);
	cube->SetPosition(-0.64f, 0.6f, 0.0f);
	cube->SetScale(0.825f, 0.1f, 0.5f);
	cube->Draw();
	//Bagian samping kanan
	cube->SetColor(117.0f, 69.0f, 12.0f);
	cube->SetPosition(-1.0f, 0.25f, 0.0f);
	cube->SetScale(0.1f, 0.6f, 0.5f);
	cube->Draw();
	//Bagian samping kiri
	cube->SetColor(117.0f, 69.0f, 12.0f);
	cube->SetPosition(-0.3f, 0.25f, 0.0f);
	cube->SetScale(0.1f, 0.6f, 0.5f);
	cube->Draw();

	//dinding
	//dinding belakang
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(0.5f, 2.0f, -0.4f);
	cube->SetScale(4.0f, 4.0f, 0.4f);
	cube->Draw();
	//dinding samping belakang
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(2.3f, 2.0f, 0.2f);
	cube->SetScale(0.4f, 4.0f, 1.0f);
	cube->Draw();
	//dinding samping bawah
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(2.3f, 0.75f, 1.7f);
	cube->SetScale(0.4f, 1.5f, 2.0f);
	cube->Draw();
	//dinding samping atas
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(2.3f, 3.25f, 1.7f);
	cube->SetScale(0.4f, 1.5f, 2.0f);
	cube->Draw();
	//dinding samping depan
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(2.3f, 2.0f, 2.7f);
	cube->SetScale(0.4f, 4.0f, 1.0f);
	cube->Draw();
	//lantai
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(0.5f, 0.0f, 1.5f);
	cube->SetScale(4.0f, 0.05f, 4.2f);
	cube->Draw();
	//dinding belakang
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(0.5f, 2.0f, 3.4f);
	cube->SetScale(4.0f, 4.0f, 0.4f);
	cube->Draw();

	//meja kanan
	cube->SetColor(22.0f, 4.0f, 80.0f);
	cube->SetPosition(0.55f, 0.25f, 0.1f);
	cube->SetScale(0.5f, 0.5f, 0.5f);
	cube->Draw();
	
	//aquarium atasnya meja kanan
	//airnya
	cube->SetColor(86.0f, 235.0f, 255.0f);
	cube->SetPosition(0.58f, 0.45f, 0.1f);
	cube->SetScale(0.4f, 0.4f, 0.4f);
	cube->Draw();
	//sisa kacanya
	cube->SetColor(187.0f, 187.0f, 187.0f);
	cube->SetPosition(0.58f, 0.67f, 0.1f);
	cube->SetScale(0.4f, 0.05f, 0.4f);
	cube->Draw();
	
	//rak kanan sebelah akuarium
	//laci bawah kiri
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.2f, 0.2f, 0.0f);
	cube->SetScale(0.4f, 0.4f, 0.4f);
	cube->Draw();
	//laci bawah tengah
	cube->SetColor(74.0f, 50.0f, 21.0f);
	cube->SetPosition(1.45f, 0.2f, 0.0f);
	cube->SetScale(0.1f, 0.4f, 0.4f);
	cube->Draw();
	//laci bawah kanan
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.7f, 0.2f, 0.0f);
	cube->SetScale(0.4f, 0.4f, 0.4f);
	cube->Draw();
	//rak bawah
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.45f, 0.6f, 0.0f);
	cube->SetScale(0.9f, 0.05f, 0.4f);
	cube->Draw();
	//rak tengah
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.45f, 1.0f, 0.0f);
	cube->SetScale(0.9f, 0.05f, 0.4f);
	cube->Draw();
	//rak atas
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.45f, 1.4f, 0.0f);
	cube->SetScale(0.9f, 0.05f, 0.4f);
	cube->Draw();
	
	//meja bawah jendela
	//atasnya
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 1.0f, 1.5f);
	cube->SetScale(0.6f, 0.08f, 1.0f);
	cube->Draw();
	//kaki kanan
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.5f, 1.1f);
	cube->SetScale(0.3f, 1.0f, 0.08f);
	cube->Draw();
	//kaki kiri
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.5f, 1.9f);
	cube->SetScale(0.3f, 1.0f, 0.08f);
	cube->Draw();

	//kardus bawah meja
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.2f, 1.6f);
	cube->SetScale(0.3f, 0.4f, 0.6f);
	cube->Draw();
	//kardus bawah meja lagi
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.5f, 1.7f);
	cube->SetScale(0.3f, 0.3f, 0.3f);
	cube->Draw();

	//kardus deket jendela
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.25f, 1.0f);
	cube->SetScale(0.5f, 0.5f, 0.5f);
	cube->Draw();

	//figura
	cube->SetColor(214.0f, 194.0f, 19.0f);
	cube->SetPosition(2.1f, 2.0f, 2.75f);
	cube->SetScale(0.01f, 0.6f, 0.5f);
	cube->Draw();

	//kabinet
	//body
	cube->SetColor(139.0f, 69.0f, 19.0f);
	cube->SetPosition(1.9f, 0.5f, 2.8f);
	cube->SetScale(0.3f, 1.0f, 0.8f);
	cube->Draw();
	//laci bawah
	cube->SetColor(74.0f, 50.0f, 21.0f);
	cube->SetPosition(1.75f, 0.3f, 2.8f);
	cube->SetScale(0.01f, 0.3f, 0.6f);
	cube->Draw();
	//laci tengah
	cube->SetColor(74.0f, 50.0f, 21.0f);
	cube->SetPosition(1.75f, 0.55f, 2.8f);
	cube->SetScale(0.01f, 0.1f, 0.6f);
	cube->Draw();
	//laci atas kiri
	cube->SetColor(74.0f, 50.0f, 21.0f);
	cube->SetPosition(1.75f, 0.8f, 2.95f);
	cube->SetScale(0.01f, 0.25f, 0.25f);
	cube->Draw();
	//laci atas kanan
	cube->SetColor(74.0f, 50.0f, 21.0f);
	cube->SetPosition(1.75f, 0.8f, 2.65f);
	cube->SetScale(0.01f, 0.25f, 0.25f);
	cube->Draw();

	glDisable(GL_DEPTH_TEST);

}

void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Cube Example", 
		1366, 768, 
		false, 
		false);
}