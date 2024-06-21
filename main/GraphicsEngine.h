#pragma once
#include <d3d11.h> /*INCLUDE DIRECTX 11 HEADER FILE*/

class GraphicsEngine
{
public:

	
	GraphicsEngine(); /*CONSTRUCTOR*/
	bool init(); /*INITIALIZATION FUNCTION */
	bool release(); /*RELEASE FUNCTION -> THIS FUNCTION IS TYPICALLY CALLED WHEN YOU WANT TO SHUT DOWN OR TERMINATE THE GRAPHICS ENGINE*/
	bool isRunning(); /*CHECK IF GRAPHICS ENGINE IS RUNNING*/
	~GraphicsEngine(); /*DESTRUCTOR*/

public:
	static GraphicsEngine* get(); /*GET THE INSTANCE OF THE GRAPHICS ENGINE*/

private:
	ID3D11Device* m_d3d_device; /*POINTER TO THE DIRECTX 11 DEVICE*/
	D3D_FEATURE_LEVEL m_feature_level; /*FEATURE LEVEL OF THE GRAPHICS CARD*/
	ID3D11DeviceContext* m_imm_context; /*POINTER TO THE IMMEDIATE CONTEXT*/
};

