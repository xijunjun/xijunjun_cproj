//#define UNICODE
//#define _UNICODE
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

#include<wchar.h>



#include"tinydir.h"
//#define _MSC_VER

//using namespace std;



int main()
{

	tinydir_dir dir;
	int i;

	//WCHAR *pdirpath = (WCHAR *)("D:\\data\\img_sample");
	//tinydir_open_sorted(&dir,pdirpath);

	//TCHAR *pdirpath = "D:\\data\\img_sample";
	//WCHAR pdirpath[100] = { '\0' };
	//wcscpy_s(pdirpath, L"D:\\data\\img_sample");

	//int ret = tinydir_open_sorted(&dir, pdirpath);



	std::string dirpath = "D:\\data\\img_sample";
	int ret = tinydir_open_sorted(&dir, (TCHAR *)dirpath.c_str());
	//tinydir_open_sorted(&dir, dirpath.c_str());


	//std::cout << pdirpath << std::endl;
	std::cout << ret << std::endl;

	std::cout << dir.n_files << std::endl;

	for (i = 0; i < dir.n_files; i++)
	{
		tinydir_file file;
		tinydir_readfile_n(&dir, &file, i);

		printf("%s", file.name);
		if (file.is_dir)
		{
			printf("/");
		}
		printf("\n");
	}

	tinydir_close(&dir);


	std::cout << "finish\n";


	system("pause");
	return 0;
}

