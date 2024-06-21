#include "GraphicsEngine.h"

// Constructor -> This function is called when an instance of the GraphicsEngine class is created
GraphicsEngine::GraphicsEngine()
{
	m_d3d_device = nullptr; // Initialize the device -> Set the device to nullptr -> nullptr is a macro that represents a null pointer value
	m_imm_context = nullptr; // Initialize the immediate context -> Set the immediate context to nullptr -> nullptr is a macro that represents a null pointer value
	m_feature_level = D3D_FEATURE_LEVEL_11_0; // Initialize the feature level -> Set the feature level to D3D_FEATURE_LEVEL_11_0 -> D3D_FEATURE_LEVEL_11_0 is an enum that represents the different versions of DirectX
}

// Initialize the Graphics Engine -> This function is typically called when you want to initialize the Graphics Engine
bool GraphicsEngine::init()
{
	// Create a device and device context
	D3D_DRIVER_TYPE driver_types[] = {
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};

	// Number of driver types -> ARRAYSIZE is a macro that returns the number of elements in an array
	UINT num_driver_types = ARRAYSIZE(driver_types);

	// Feature levels -> D3D_FEATURE_LEVEL is an enum that represents the different versions of DirectX
	D3D_FEATURE_LEVEL feature_levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};

	// Number of feature levels -> ARRAYSIZE is a macro that returns the number of elements in an array
	UINT num_feature_levels = ARRAYSIZE(feature_levels);

	HRESULT res = 0;
	for (UINT driver_type_index = 0; driver_type_index < num_driver_types; )
	{
		res = D3D11CreateDevice(
			NULL, // Use the default adapter -> This is a pointer to the adapter -> This is an input parameter -> pointer to the adapter that represents the graphics card
			driver_types[driver_type_index], // Use the current driver type -> This is an enum that represents the different types of drivers
			NULL, // Do not use a software device -> This is a pointer to the software device -> This is an output parameter
			NULL, // Do not set any flags -> This is a mask that specifies options for device creation -> This is a combination of one or more D3D11_CREATE_DEVICE_FLAG values
			feature_levels, // Use the current feature levels
			num_feature_levels, // Use the current number of feature levels -> feature levels is an array that contains the different versions of DirectX
			D3D11_SDK_VERSION, // Use the current SDK version -> This is a macro that represents the version of the DirectX SDK
			&m_d3d_device, // Set the device -> This is an output parameter -> The device is created and stored in this variable -> This is a pointer to the device
			&m_feature_level, // Set the feature level -> This is an output parameter -> The feature level is created and stored in this variable -> This is a pointer to the feature level
			&m_imm_context // Set the immediate context -> This is an output parameter -> The immediate context is created and stored in this variable -> This is a pointer to the immediate context
		);

		if(SUCCEEDED(res)) // If the device was created successfully -> SUCCEEDED is a macro that returns true if the HRESULT is a success code
		{
			break; // Break the loop -> Exit the loop
		}

		++driver_type_index; // Increment the driver type index -> Increment the driver type index by 1
	}

	if (FAILED(res))
	{
		return false; // Return false -> The device was not created successfully
	}

	return true;
}

// Release the Graphics Engine -> This function is typically called when you want to shut down or terminate the Graphics Engine
bool GraphicsEngine::release()
{
	m_imm_context->Release(); // Release the immediate context -> Release is a function that releases a COM object -> This is a pointer to the immediate context
	m_d3d_device->Release(); // Release the device -> Release is a function that releases a COM object -> COM is a Component Object Model -> This is a pointer to the device
	return true;
}

// Check if the Graphics Engine is running -> This function is typically called when you want to check if the Graphics Engine is running
bool GraphicsEngine::isRunning()
{
	return false;
}

// Destructor -> This function is called when an instance of the GraphicsEngine class is deleted
GraphicsEngine::~GraphicsEngine()
{
}

// Get the instance of the GraphicsEngine -> This is a singleton pattern -> singleton is a design pattern that restricts the instantiation of a class to one object
GraphicsEngine* GraphicsEngine::get()
{
	static GraphicsEngine engine; // Create a static instance of the GraphicsEngine class -> This is a singleton pattern
	return &engine;
}
