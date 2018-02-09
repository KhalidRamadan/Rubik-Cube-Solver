#pragma once


#include <opencv2/opencv.hpp>
#include<string>
#include<iostream>
// red
// green - yellow - blue - white
// orange


namespace vision
{


	enum colors
	{
		WHITE, // 0
		BLUE, // 1
		YELLOW, // 2
		GREEN, // 3
		RED, // 4
		ORANGE // 5

	};


	class Scanner
	{
	private:
		cv::VideoCapture m_Camera;
		std::string m_WindowName;
		int m_IndexCamera = 0;
	public:
		Scanner(std::string WindowName);
		Scanner(std::string WindowName, int IndexCamera);
		~Scanner();
		void Update();

	private:
		void Init();

	};

}