#include "coloring.h"
#include <list>
#include <cmath>

Coloring::Coloring(int n, GraphM *g){
    this->g = g;
    this->colors = new std::vector<int>(n,-1);
}

bool Coloring::isSafe(int pos, int color)
{
    std::list<int> &list = g->neighbors(pos);
    std::vector<int > ref(g->n(),0);
    for(auto begin = list.begin() ; begin != list.end() ; ++begin){

        ref[*begin] = 1;
        if( *begin >= 0 && std::abs( color- (g->colorsArray()->at(*begin)) ) < 3)
            return false;
    }

//    // distância 2
    std::list<std::list<int>> vizinhos;
    for(auto begin = list.begin() ; begin != list.end() ; ++begin){
        std::list<int> distance2 = g->neighbors(*begin);
        distance2.remove(pos);
        vizinhos.push_back(distance2);

        for(auto init = distance2.begin() ; init != distance2.end() ; init++){
            if(ref[*init]) continue;
            ref[*init] = 1;
            if( *init >= 0 && std::abs( color- (g->colorsArray()->at(*init)) ) < 2)
                return false;
        }
    }

    //Distancia 3
    for(auto begin = vizinhos.begin() ; begin != vizinhos.end(); begin++){
       for(auto init = begin->begin() ; init != begin->end() ; init++){
           std::list<int> distance3 = g->neighbors(*init);
           distance3.remove(pos);

           for(auto d3 = distance3.begin() ; d3 != distance3.end(); d3++){
                if(ref[*d3]) continue;
                ref[*d3] = 1;
                if( *d3 >= 0 && std::abs( color- (g->colorsArray()->at(*d3)) ) < 1)
                    return false;
           }
       }
    }

    return true;

}




std::vector<int>* Coloring::kColoring(int i)
{
    int count = g->n();

    while(count){

        std::list<int> vizinhos =  g->neighbors(i);

        int c= 0;

        int proxV = -1;

        for(auto v : vizinhos ){
            if( colors->at(v) >= 0 ){
                if(abs(c - colors->at(v)) < 2){
                    if(colors->at(v)+1 == 2)
                        c =colors->at(v) + 1;
                    else c =colors->at(v) + 2;

                    auto diameter =  g->neighbors(v);
                    for(auto vX : diameter){
                        if(vX == i || vX == v) continue;
                        if(colors->at(vX) >= 0){
                            if(c == colors->at(vX) ){
                                c++;
                                if(abs(c - colors->at(v)) < 2) c++;
                                continue;
                            }
                        }
                    }

                }
                if(proxV == -1 && colors->at(v) == -1){
                    proxV = v;
                }
                continue;

            }
            colors->insert(colors->begin()+i, c);
            count --;
            i= proxV;
            proxV = -1;

        }
    }
    return colors;
}

int Coloring::l321(int index, int lambda, int color)
{
    std::vector<int> *colors = this->g->colorsArray();
    if(std::find(colors->begin(), colors->end(), -1) == colors->end()){
        for( auto content : *colors){
            std::cout<< content <<" ";
        }
        std::cout<< "\n";
        return 1;
    }

    for(int i = 0 ; i< lambda+1 ; i++){
        if(this->isSafe(index, i)){
            (*colors)[index] = i;
            this->l321(index+1, lambda, color );

                (*colors)[index] = -1;
        }
    }
    return 0;
}

Coloring::~Coloring(){

}
