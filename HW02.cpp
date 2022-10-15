#include <iostream>
#include <ctime>
#include <queue>
#include <cstdlib>

using namespace std;

struct Student{
    int timeNeeded;
    int startTime;
};

int main(){
    
    srand(time(0));
    
    queue<Student> student;
    int studentServed = 0;
    int totTimeOffice = 0;
    int totWaitTime = 0;
    int profTime = 0;
    int totalTotProfTime = 0;
    double aveWaitTime = 0;
    double aveOfficeTime = 0;
    double totalAveOfficeTime = 0;
    double totalAveWaitTime = 0;
    
    for(int i = 0; i < 101; i++){
        for(int i = 1; i < 61; i++){
            
            if(rand()%10 < 1){                          //Change rand()% if different odds are needed
                studentServed++;
                Student a = {rand()%10 + 1, i};         //Change rand()% if different odds are needed
                totTimeOffice += a.timeNeeded;
                student.push(a);
            }
            
            if(!student.empty()){
                --student.front().timeNeeded;
                if(student.front().timeNeeded == 0){
                    student.pop();
                    if(!student.empty()){
                        totWaitTime = (i + 1) - student.front().startTime;
                    }
                }
            }
            
            
        }
        
        for(int i = 61; !student.empty(); i++){
            if(!student.empty()){
                --student.front().timeNeeded;
                if(student.front().timeNeeded == 0){
                    student.pop();
                    if(!student.empty()){
                        totWaitTime += (i + 1) - student.front().startTime;
                    }
                    profTime = i - 61;
                }
            }
            
        }
        
        aveOfficeTime = totTimeOffice / studentServed;
        aveWaitTime = totWaitTime / studentServed;
        
        totalAveOfficeTime += aveOfficeTime;
        totalAveWaitTime += aveWaitTime;
        totalTotProfTime += profTime;
    }
    
    cout << "The average time a student spends waiting during an office hour visit: " << totalAveWaitTime / 100 << " miutes." << endl;
    cout << "The average time a student spends with the professor during an office hour visit: " << totalAveOfficeTime / 100 << " miutes." << endl;
    cout << "The average time a Professor spends at an office hour beyond the 1 hour he intended to: " << totalTotProfTime / 100 << " miutes." << endl;
    
    return 0;
}
/*
 
               *    *
          *              *
     *       *    *           *
*       *                 *        *
                _..  *
  ___..-"""-.  `)^|   .-"""-..___
 `-...___ '=.'-.'  \-'.=' ___...-'
         `\  '  _|_  '  /`
           '--;  |  ;--'
              /\   /\
             ( /;-;\ )
              '-...-'
 
 */
