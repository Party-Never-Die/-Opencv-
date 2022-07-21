需要修改的地方就是main.cpp中  
argv[1]="/home/hehe/Desktop/1.jpg";//对应图片为原始图，重命名即可，修改自己的载入路径  
在Ubuntu18.04系统下使用Kdevelop软件进行编译  
(1)在Kdevelop软件下打开Project-Open/Import Project-一直Next就行  
(2)载入文件后，点击左上角Build或F8进行编译-shift+F9执行二进制文件  
快捷键：注释多行代码:ctrl+d  
       取消注释多行代码:ctrl+shift+d  
或者  
(1)进入文件夹右击在终端打开  
mkdir build  
cd build  
cmake ..  
make -j8（-j8代表8线程编译）  
(2)终端执行二进制文件  
cd build  
./main  
 2022-7-21 
 增加灰度变化，膨胀 
 
 
 
