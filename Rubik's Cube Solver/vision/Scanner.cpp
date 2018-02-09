
#include "Scanner.h"
#include <iostream>


namespace vision
{
	Scanner::Scanner(std::string WindowName)
	{
		m_WindowName = WindowName;
		Init();
	}

	Scanner::Scanner(std::string WindowName, int IndexCamera)
	{
		m_WindowName = WindowName;
		m_IndexCamera = IndexCamera;
		Init();
	}

	void Scanner::Init()
	{
		m_Camera.open(m_IndexCamera);
		cv::namedWindow(m_WindowName);
		if (m_Camera.isOpened() == false)
		{
			std::cout << "Cannot open the video camera" << std::endl;
			system("PAUSE");
		}

	}

	void Scanner::Update()
	{
		while (true)
		{
			cv::Mat frame;
			bool bSuccess = m_Camera.read(frame); 
			if (bSuccess == false)
			{
				std::cout << "Video camera is disconnected" << std::endl;
				system("PAUSE");
				break;
			}

			imshow(m_WindowName, frame);

			if (cv::waitKey(10) == 27)
			{
				std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
				break;
			}
		}
	}


	Scanner::~Scanner()
	{
		cv::destroyWindow(m_WindowName);
	}





}