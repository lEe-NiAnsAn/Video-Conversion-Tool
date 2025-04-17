# Video-Conversion-Tool
One small tool to convert  the videos to AVI using OpenCV
------
## *使用方式* 
- 运行安装程序，添加程序目录
- 使用 `cmd` 打开程序目录
- 命令行中输入 “程序名”+“待处理文件URL”+“输出URL”

### <ins>简易方式</ins>
- 创建一个工作文件夹，将待处理文件置于其中
- 打开程序目录
- 使用鼠标将待处理文件拖至程序（.exe文件）上方并使用本程序打开
- 处理完毕，程序自动于工作文件夹内输出output文件夹，内含处理后文件
  
**例如：**
 ```cmd
D:\...> video_conversion.exe ./test.mp4 ./out/out.avi
```
> *注意：* 命令行参数第三项拥有缺省值 `./output/output,avi`
------
该程序可在 *Windows* 下进行OpenCV支持解析读取的常规视频格式转换至AVI
> 使用 [Inno Setup](https://jrsoftware.org/isinfo.php "官网地址")[中文版](# "感谢杜敏俊大佬以及所有前辈的汉化！") 进行安装程序打包
