#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char** argv) {   // argv[0]为本程序的名称，argv[1]为输入视频文件路径，argv[2]为输出视频文件路径
    std::string inputPath, outputPath;
    // 检查命令行参数
    if (argc < 2) {
        std::cerr << argv[0] << ": 参数输入错误" << std::endl;
        return -1;
    }
    else if (argc == 2) {
        // 设置默认输出路径
        inputPath = argv[1];
        outputPath = "./outputFile/output.avi"; // 默认输出文件名
    }
    else {
        inputPath = argv[1];
        outputPath = argv[2];
    }

    // 确保输出目录存在
    std::filesystem::path outputDir = std::filesystem::path(outputPath).parent_path();
    if (!outputDir.empty() && !std::filesystem::exists(outputDir)) {
        std::filesystem::create_directories(outputDir);
    }

    // 打开输入视频文件
    cv::VideoCapture inputVideo(inputPath);
    if (!inputVideo.isOpened()) {
        std::cerr << inputPath << ": 路径不存在或无法以视频格式打开路径" << std::endl;
        return -1;
    }

    // 获取输入视频的属性
    double fps = inputVideo.get(cv::CAP_PROP_FPS);  // 帧率
    int width = static_cast<int>(inputVideo.get(cv::CAP_PROP_FRAME_WIDTH)); // 视频宽度
    int height = static_cast<int>(inputVideo.get(cv::CAP_PROP_FRAME_HEIGHT)); // 视频高度
    cv::Size frameSize(width, height);

    // 初始化输出视频写入对象
    cv::VideoWriter outputVideo;
    int fourcc = cv::VideoWriter::fourcc('X', 'V', 'I', 'D'); // 使用XVID编码指定视频编码格式为.avi
    outputVideo.open(outputPath, fourcc, fps, frameSize, true);    // 参数分别为输出视频文件路径、编码格式、帧率、视频尺寸、是否彩色

    if (!outputVideo.isOpened()) {
        std::cerr  << outputPath << ": 路径不存在或无法以视频格式保存至该路径" << std::endl;
        return -1;
    }

    // 读取并写入视频帧
    cv::Mat frame;
    while (inputVideo.read(frame)) {
        if (frame.empty()) {
            break;
        }
        outputVideo.write(frame); 
    }

    // 释放资源
    inputVideo.release();
    outputVideo.release();

    std::cout << "转换完成" << std::endl;
    return 0;
}