#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>


class node{
int color{-1},distance{-1}, index,fatherin;
public:
    int getFatherin() const {
        return fatherin;
    }

    void setFatherin(int fatherin) {
        node::fatherin = fatherin;
    }

private:
    std::vector<int> adjacent;
public:
    int getColor() const {
        return color;
    }

    int getDistance() const {
        return distance;
    }

    int getFather() const {
        return index;
    }

    const std::vector<int> &getAdjacent() const {
        return adjacent;
    }

    void setColor(int color) {
        node::color = color;
    }

    void setDistance(int distance) {
        node::distance = distance;
    }
node(std::vector<int> adj,int index):adjacent(adj),index(index){};
void setfather(int a){index=a;}


};
class digraph{
    std::deque<node> list;
public:
    void bfs(){
        std::deque<node> temp;
        list.at(0).setColor(0);
        list.at(0).setDistance(0);
        list.at(0).setFatherin(0);
        temp.push_back(list.at(0));
        while(!temp.empty()){
                node u = temp.at(0);std::cout << "Hello, World!" << std::endl;
                for(int index : u.getAdjacent()){
                    if(list.at(index).getColor()==-1){
                        list.at(index).setColor(0);
                        list.at(index).setDistance(u.getDistance()+1);
                        list.at(index).setFatherin(u.getFather());
                        temp.push_back(list.at(index));
                    }
                    list.at(u.getFather()).setColor(1);
                }
                temp.pop_front();
        }
    }
    void print(){
        std::cout<<"size = "<<list.size()<<"\n";
        for(node a: list)
        std::cout<<"color = "<<a.getColor()<<" father = "<<a.getFatherin()<<" distance = "<<a.getDistance()<<"\n";
    }
    digraph(std::ifstream &f1){
        std::string str{};
        int temp{};

        while (std::getline(f1, str)) { //read file until the end line by line
            int count{0};
            std::vector<int> adjacent;
            std::istringstream ss(str);
            while (ss >> temp)  {
                count++;
                if(temp == 1){
                    adjacent.push_back(count-1);
                }
            };
            list.push_back(node(adjacent,list.size()));

        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::ifstream file("digraph");
    std::cout << "Hello, World!" << std::endl;
    digraph digraphobj(file);std::cout << "Hello, World!" << std::endl;
    digraphobj.bfs();std::cout << "Hello, World!" << std::endl;
    digraphobj.print();std::cout << "Hello, World!" << std::endl;
    return 0;
}