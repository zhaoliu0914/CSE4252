#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char*argv[]) {
    std::string last(argv[argc - 1]);
    std::string flag = "-s";
    bool sqflag = false;

    if(argc < 3){
        std::cout << "This program requires at lest 2 input files." << std::endl;
        exit(10);
    }

    if (!last.compare(flag)) {
        // Squeeze the empty line
        sqflag = true;
    }

    //std::cout << "argc = " << argc << std::endl;
    //std::cout << "argv[0] = " << argv[0] << std::endl;
    //std::cout << "argv[1] = " << argv[1] << std::endl;
    //std::cout << "argv[2] = " << argv[2] << std::endl;
    //std::cout << "argv[3] = " << argv[3] << std::endl;

    std::string firstFileName = argv[1];
    std::string secondFileName = argv[2];

    std::ifstream firstFile(firstFileName);
    std::ifstream secondFile(secondFileName);

    if(!firstFile.is_open()){
        std::cerr << "Unable to open file "<< firstFileName << std::endl;
    }
    if(!firstFile.is_open()){
        std::cerr << "Unable to open file "<< firstFileName << std::endl;
    }

    std::string line;
    bool isEmpty = false;
    while (std::getline(firstFile, line)) {
        // print each line in the file

        //std::cout << "line.size() = " << line.size() << std::endl;
        //std::cout << "line.empty() = " << line.empty() << std::endl;
        if(sqflag){
            if(!line.empty()){
                std::cout << line << std::endl;
                isEmpty = false;
            } else if(line.empty() && isEmpty == false){
                std::cout << line << std::endl;
                isEmpty = true;
            }
        }else{
            std::cout << line << std::endl;
        }
    }

    while (std::getline(secondFile, line)) {
        // print each line in the file
        if(sqflag){
            if(!line.empty()){
                std::cout << line << std::endl;
                isEmpty = false;
            } else if(line.empty() && isEmpty == false){
                std::cout << line << std::endl;
                isEmpty = true;
            }
        }else{
            std::cout << line << std::endl;
        }
    }

    // Close the file after reading
    firstFile.close();
    secondFile.close();

    return 0;
}
