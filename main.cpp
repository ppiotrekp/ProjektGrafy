#include <iostream>
#include <queue>
#include <string.h>
#include <fstream>
#include <climits>
#define V 11

using namespace std;

bool bfs(int rGraph[V][V], int s, int t, int parent[]);

int fordFulkerson(int graph[V][V], int s, int t){
    int u, v;
    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0; //maksymalna przepustowosc

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX; //znajduje maksymalny przeplyw przez znaleziona sciezke
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

bool bfs(int rGraph[V][V], int s, int t, int parent[]){ //funkcja typu bool zwracająca wartość true jeśli istnieje ścieżka od źródła do ujścia
    bool searched[V]; //tablica, która oznacza zbadane przez nas wierzchołki, na początku ustawiona na wartosc domyslna czyli 0 zbadanych wierzcholkow
    memset(searched, 0, sizeof(searched));
    queue<int> q; //kolejka
    q.push(s); //dodawanie do kilejki
    searched[s] = 1;
    parent[s] = -1; //element nadrzedny nie istnieje

    //przeszukiwanie wszerz
    while (q.empty()==0) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) { //jesli znajdziemy polaczenie z wezlem ujscia, ustawiamy element nadrzedny, ktory zwraca true
            if (!(searched[v]) && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return 1;
                }
                q.push(v);
                parent[v] = u;
                searched[v] = 1;
            }
        }
    }

    return 0;
}

int main(){
    return 0;
}

//    ifstream myfile ("JSON.txt");
//    if (!myfile.fail())
//    {
//        //cout << "JSON: ";
//        int graph[V][V];
//        string line;
//        string delimiter = ",";
//        int pos = 0;
//        string token;
//       string table_of_elements[V][V];
//        int i=0;
//        int j=0;
//        while (!myfile.eof())
//        {
//            getline(myfile, line);
//            while ((pos = line.find(delimiter)) != string::npos) {
//                token = line.substr(0,pos);
//                graph[i][j] = stoi(token);
//                line.erase(0, pos+delimiter.length());
//                i++;
//            }
//            j++;
//        }

//         for (int i=0; i<V; i++) {
//             for (int j=0; j<V; j++) {
//                 graph[i][j] = stoi(table_of_elements[i][j]);
//             }
//         }



//    int graph[V][V];
//
//
