#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

#include"tinydir.h"


using namespace std;

vector<string> get_ims(string srcroot)
{
	vector<string> imlist;
	tinydir_dir dir;
	int i;
	tinydir_open_sorted(&dir, srcroot.c_str());

	for (i = 0; i < dir.n_files; i++)
	{
		tinydir_file file;
		tinydir_readfile_n(&dir, &file, i);

		// printf("%s", file.name);
		if (file.is_dir)
		{
			// printf("/");
		}
		else
		{
			//if()
			cout << "extension:" << file.extension << endl;
			string ext(file.extension);
			std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
			std::cout << ext << std::endl;
			imlist.push_back(file.name);
		}
		// printf("\n");
	}

	tinydir_close(&dir);

	return imlist;
}






int main()
{


	vector<string>  ims = get_ims("D:\\data\\img_sample");
	for (int i = 0; i<ims.size(); i++)
	{
		cout << ims[i] << endl;
	}

	std::cout << "finish\n";


	system("pause");
	return 0;
}

