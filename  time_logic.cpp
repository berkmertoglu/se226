#include <iostream>
int main() {
    long total_seconds;
    std::cout<< "Enter a large integer: ";
    std::cin >> total_seconds;
    int hours=total_seconds/3600;
    int remaining_seconds=total_seconds%3600;
    int minutes=remaining_seconds/60;
    int seconds=remaining_seconds%60;
    std::cout<<total_seconds<<"seconds is"<<hours<<"hours,"<< minutes<< " minutes,and" <<seconds << "seconds."<<std::endl;
    return 0;
}