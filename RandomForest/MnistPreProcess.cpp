#include"MnistPreProcess.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getext(const char* filename)
{
	string ext;
	string filepath = filename;
	ext = filepath.substr(filepath.find_last_of('.') + 1);
	return ext;
}
int split(std::string token[], std::string s, char d)
{
	int begin = 0;
	int end = 0;
	int count = 0;
	for (unsigned int i = 0; i < s.length(); ++i) {
		if (i == s.length() - 1 && s[i] != d) {
			end = s.length();
			token[count] = std::string(s, begin, end - begin);
			++count;
			begin = end + 1;
		}
		else if (s[i] == d) {
			end = i;
			token[count] = std::string(s, begin, end - begin);
			++count;
			begin = end + 1;
		}
	}
	return count;
}

void readData(float** dataset,float*labels,const char* dataPath,const char*labelPath)
{
	//string filepath = "1111.txt";
	//string suffixStr = filepath.substr(filepath.find_last_of('.') + 1);
	string ext = getext(dataPath);
	if (ext == "txt")//txt��ʽ����
	{
		return;
	}
	else if(ext=="csv")//csv��ʽ����
	{
		fstream fs;
		fs.open(dataPath, fstream::in);
		//ȥ����һ�У����ֶ�ͷ,s�����ڴ��浱ǰ�е���ʱ����
		std::string s;
		std::getline(fs, s);

		std::string token[FEATURE];
		//����ѵ����
		int i, j;
		int trainID[TRAIN_NUM];                                       //ѵ����ÿһ�м�¼��ID�������ʵ�������û��������

		for (i = 0; i < TRAIN_NUM ; i++)
		{
			std::getline(fs, s);
			int count = split(token, s, ',');
			trainID[i] = stoi(token[0]);
			for (j = 1; j < FEATURE - 1; j++) 
			{
				double t;
				t = std::stod(token[j]);
				dataset[i][j - 1] = t;
				//cout << t << " ";
			}
			labels[i] = std::stod(token[j]);
			//cout << labels[i] << endl;
		}
		fs.close();
		//������Լ�
		//fs.open(testsetPath.c_str(), std::fstream::in);
		//std::getline(fs, s);
		//for (i = 0; i< testsetNum; i++)
		//{
		//	std::getline(fs, s);
		//	//std::string token[numparametres];
		//	int count = split(token, s, ',');
		//	testID[i] = stoi(token[0]);
		//	for (j = 1; j < numparametres - 1; j++)
		//	{
		//		double t;
		//		t = std::stod(token[j]);
		//		testIn[i][j - 1] = t;
		//	}
		//	//testOut[i][0] = std::stod(token[j]);
		//	//dt_out[i][0] = std::stod(token[j]);
		//}
		//fs.close();
	}
	else if (ext == "xlsx")//excel��ʽ����
	{
		return;
	}
	else if(ext==dataPath)//�����Ƹ�ʽ����
	{
		FILE* dataFile = fopen(dataPath, "rb");
		FILE* labelFile = fopen(labelPath, "rb");
		int mbs = 0, number = 0, col = 0, row = 0;
		fread(&mbs, 4, 1, dataFile);
		fread(&number, 4, 1, dataFile);
		fread(&row, 4, 1, dataFile);
		fread(&col, 4, 1, dataFile);
		revertInt(mbs);
		revertInt(number);
		revertInt(row);
		revertInt(col);
		fread(&mbs, 4, 1, labelFile);
		fread(&number, 4, 1, labelFile);
		revertInt(mbs);
		revertInt(number);
		unsigned char temp;
		for (int i = 0; i<number; ++i)
		{
			for (int j = 0; j<row*col; ++j)
			{
				fread(&temp, 1, 1, dataFile);
				dataset[i][j] = static_cast<float>(temp);
			}
			fread(&temp, 1, 1, labelFile);
			labels[i] = static_cast<float>(temp);
		}
		fclose(dataFile);
		fclose(labelFile);
	}
	//FILE* dataFile=fopen(dataPath,"rb");
	//FILE* labelFile=fopen(labelPath,"rb");
	//int mbs=0,number=0,col=0,row=0;
	//fread(&mbs,4,1,dataFile);
	//fread(&number,4,1,dataFile);
	//fread(&row,4,1,dataFile);
	//fread(&col,4,1,dataFile);
	//revertInt(mbs);
	//revertInt(number);
	//revertInt(row);
	//revertInt(col);
	//fread(&mbs,4,1,labelFile);
	//fread(&number,4,1,labelFile);
	//revertInt(mbs);
	//revertInt(number);
	//unsigned char temp;
	//for(int i=0;i<number;++i)
	//{
	//	for(int j=0;j<row*col;++j)
	//	{
	//		fread(&temp,1,1,dataFile);
	//		dataset[i][j]=static_cast<float>(temp);
	//	}
	//	fread(&temp,1,1,labelFile);
	//	labels[i]=static_cast<float>(temp);
	//}
	//fclose(dataFile);
	//fclose(labelFile);
};
void readData2(float** dataset, float*labels, const char* dataPath)
{
	//string filepath = "1111.txt";
	//string suffixStr = filepath.substr(filepath.find_last_of('.') + 1);
	string ext = getext(dataPath);
	if (ext == "txt")//txt��ʽ����
	{
		return;
	}
	else if (ext == "csv")//csv��ʽ����
	{
		fstream fs;
		fs.open(dataPath, fstream::in);
		//ȥ����һ�У����ֶ�ͷ,s�����ڴ��浱ǰ�е���ʱ����
		std::string s;
		std::getline(fs, s);

		std::string token[FEATURE];
		//����ѵ����
		int i, j;
		int testID[TEST_NUM];                                       //ѵ����ÿһ�м�¼��ID�������ʵ�������û��������

		for (i = 0; i < TEST_NUM; i++)
		{
			std::getline(fs, s);
			int count = split(token, s, ',');
			testID[i] = stoi(token[0]);
			for (j = 1; j < FEATURE - 1; j++)
			{
				double t;
				t = std::stod(token[j]);
				dataset[i][j - 1] = t;
				//cout << t << " ";
			}
			labels[i] = std::stod(token[j]);
			//cout << labels[i] << endl;
		}
		fs.close();
		//������Լ�
		//fs.open(testsetPath.c_str(), std::fstream::in);
		//std::getline(fs, s);
		//for (i = 0; i< testsetNum; i++)
		//{
		//	std::getline(fs, s);
		//	//std::string token[numparametres];
		//	int count = split(token, s, ',');
		//	testID[i] = stoi(token[0]);
		//	for (j = 1; j < numparametres - 1; j++)
		//	{
		//		double t;
		//		t = std::stod(token[j]);
		//		testIn[i][j - 1] = t;
		//	}
		//	//testOut[i][0] = std::stod(token[j]);
		//	//dt_out[i][0] = std::stod(token[j]);
		//}
		//fs.close();
	}
	else if (ext == "xlsx")//excel��ʽ����
	{
		return;
	}
}
