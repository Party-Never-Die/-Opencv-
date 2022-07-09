#include <iostream>
#include <chrono>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
int main ( int argc, char **argv )
{
    argv[1]="/home/hehe/Desktop/1.jpg";//对应图片为原始图，重命名即可
    // 读取argv[1]指定的图像
    cv::Mat image;
    image= cv::imread ( argv[1] ); //cv::imread函数读取指定路径下的图像
    // 判断图像文件是否正确读取
    if ( image.data == nullptr ) //数据不存在,可能是文件不存在
    {
        cerr<<"文件"<<argv[1]<<"不存在."<<endl;
        return 0;
    }
    // 文件顺利读取, 首先输出一些基本信息
    cout<<"图像宽为"<<image.cols<<",高为"<<image.rows<<",通道数为"<<image.channels()<<endl;
    cv::imshow ( "image", image );      // 用cv::imshow显示图像
    cv::waitKey ( 0 );                  // 暂停程序,等待一个按键输入
    // 判断image的类型
    if ( image.type() != CV_8UC1 && image.type() != CV_8UC3 )
    {
    // 图像类型不符合要求
        cout<<"请输入一张彩色图或灰度图."<<endl;
        return 0;
    }

    // 遍历图像, 请注意以下遍历方式亦可使用于随机像素访问
    // 使用 std::chrono 来给算法计时
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    for ( size_t y=0; y<image.rows; y++ )
    {
    // 用cv::Mat::ptr获得图像的行指针
        unsigned char* row_ptr = image.ptr<unsigned char> ( y );  
    // row_ptr是第y行的头指针
        for ( size_t x=0; x<image.cols; x++ )
        {
    // 访问位于 x,y 处的像素
            unsigned char* data_ptr = &row_ptr[ x*image.channels() ]; 
    // data_ptr 指向待访问的像素数据
    // 输出该像素的每个通道,如果是灰度图就只有一个通道
            for ( int c = 0; c != image.channels(); c++ )
            {
                unsigned char data = data_ptr[c]; 
    // data为I(x,y)第c个通道的值
            }
        }
    }
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>( t2-t1 );
    cout<<"遍历图像用时："<<time_used.count()<<" 秒。"<<endl;
    // 关于 cv::Mat 的拷贝
    // 直接赋值并不会拷贝数据
    cv::Mat image_another = image;
    // 修改 image_another 会导致 image 发生变化
    image_another ( cv::Rect ( 0,0,100,100 ) ).setTo ( 0 ); 
    // 将左上角100*100的块置零
    cv::imshow ( "image", image );
    cv::waitKey ( 0 );
    // 使用clone函数来拷贝数据
    cv::Mat image_clone = image.clone();
    image_clone ( cv::Rect ( 0,0,100,100 ) ).setTo ( 255 );
    cv::imshow ( "原始图", image );
    cv::imshow ( "克隆图", image_clone );
    cv::waitKey ( 0 );
    cv::destroyAllWindows();
    //图像腐蚀
    //Mat getStructuringElement(int shape, Size esize, Point anchor = Point(-1, -1));
    //这个函数会返回指定形状和尺寸的结构元素的第一个参数表示内核的形状，有三种形状可以选择。
    //矩形：MORPH_RECT交叉形：MORPH_CROSS;椭圆形：MORPH_ELLIPSE;
    //第二和第三个参数分别是内核的尺寸以及锚点的位置。
    //一般在调用erode以及dilate函数之前，先定义一个Mat类型的变量来获得getStructuringElement函数的返回值。
    //对于锚点的位置，有默认值Point（-1,-1），表示锚点位于中心点。
    //element形状唯一依赖锚点位置，其他情况下，锚点只是影响了形态学运算结果的偏移。
    //element也是腐蚀操作的内核。 如果不指定，默认为一个简单的 3x3 矩阵
    cv::Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	cv::Mat dstimage;
	cv::erode(image, dstimage, element);
	//显示效果图 
	cv::imshow("腐蚀", dstimage);
	cv::waitKey(0);
    //Sobel边缘检测；
    //void Sobel( InputArray src, OutputArray dst, int ddepth,
    //int dx, int dy, int ksize = 3,
    //double scale = 1, double delta = 0,
    //int borderType = BORDER_DEFAULT );
    //Sobel边缘检测InputArray类型的image，输入图像，8位图像。
    //OutputArray类型的dst，输出图像。
    //int类型的ddepth，输出图像的深度。若src为CV_8U，则可取-1/CV_16S/CV_32F/CV_64F；
    //若src为CV_16U/CV_16S，可取-1/CV_32F/CV_64F；
    //若src为CV_32F，可取-1/CV_32F/CV_64F；若src为CV_64F，可取-1/CV_64F。
    //int类型的dx，x方向上的差分阶数。int类型的dy，y方向上的差分阶数。
    //int类型的ksize，默认值为3，表示Sobel核的大小，取奇数。
    //double类型的scale，计算导数值时选的缩放因子，默认为1。
    //double类型的delta，表示在结果存入目标图之前可选的delta值，默认为0。
    //int类型的borderType，边界模式。
    Mat src =cv::imread ( argv[1] );
	Mat gradx, grady, absgradx, absgrady, result;
	// X方向梯度
	Sobel(src, gradx, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gradx, absgradx);
	// Y方向梯度
	Sobel(src, grady, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grady, absgrady);
	// 梯度相加
	addWeighted(absgradx, 0.5, absgrady, 0.5, 0, result);
	// 结果显示
	imshow("原始图", src);
	imshow("X方向梯度", absgradx);
	imshow("Y方向梯度", absgrady);
	imshow("整体方向梯度", result);
	waitKey(0);
    return 0;
}
