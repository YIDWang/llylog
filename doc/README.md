针对文件底层封装的选取，选取C++封装的文件操作流，主要因素有如下：
在cpu和内存方面，日志作为程序的必备单元，应该尽量低的占用内存和cpu，使之不影响主程序运行。C++的文件流和fwrite效果相当，明显好于c的write
在效率方面，对于效率不要求太高，C++的文件流和fwrite效果相当，次于c的write。
在复杂度方面,mmap虽然效率很高但是复杂度较高，容易丢失日志，不易控制，