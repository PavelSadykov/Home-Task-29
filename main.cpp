//
//  main.cpp
//  C++ ДЗ 29
//
//  Created by Павел on 07.11.2022.
//

#include <iostream>
#include <fstream>
#include <string>

std::string overwrite(std::string Way,std::string Str);

int main(int argc, const char * argv[]) {
   
   std::cout<<"Задача 1.\n";
   std::string file = "fileX";
   std::ofstream fs;
   fs.open(file,std::ios::app);
    if(!fs.is_open()){
        std::cout<<"Файл не удалось открыть \n";
    }else
    {   std::cout<<"(Файл fileX.txt открыт) \n";
        std::string str;
        do {
            std::cout<<"Введите строки , по завершению введите end  \n";
             std::getline(std::cin,str);
             fs << str << "\n";//Запись в файл
             } while (str != "end");
    } fs.close();
    
    std::string str1;
    std::ifstream fs1;
    fs1.open(file);
    if(!fs1.is_open()){
        std::cout<<"Файл не удалось открыть \n";
    }else
    {   std::cout<<"(Файл fileX.txt открыт) \n";
        while (!fs1.eof()) {
                  fs1 >> str1;//Чтение из файла
        std::cout << str1 << std::endl;
        }}
    fs1.close();
   
    remove("fileX");
    
    
    
    std::cout<<"Задача 2.\n";
    std::string Way = "fileX.txt";
    std::string Str;
    std::cout<<"Введите строку :\n";
    std::cin>>Str;
    std::cout<<overwrite(Way,Str);
    
    return 0;
}

std::string overwrite(std::string Way,std::string Str){
    std::string result;
    std::string Str1;
    std::ofstream fs3;
    fs3.open(Way,std::ios::out);
    if(!fs3.is_open()){
        std::cout<<"Файл не удалось открыть\n";
        result="FALSE";
    }else
    {
        std::cout<<"(Файл открыт)\n";
        fs3 << Str;
        fs3.close();
    }
    
    std::ifstream fs4;
    fs4.open(Way);
    if(!fs4.is_open()){
            std::cout<<"Файл не удалось открыть\n";
        }else
    {
        std::cout<<"(Файл открыт)\n";
        fs4>>Str1;
        std::cout<<Str1;
        if (Str==Str1)
            result="\nTRUE\n";
        
    }
        fs4.close();
    
    return result;
}
