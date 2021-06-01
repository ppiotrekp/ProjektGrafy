#include <iostream>
#include <queue>
#include <string.h>
#include <string>
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

int main() {
    ifstream content ("C:\\Users\\48886\\CLionProjects\\podstawy_programowania_2-\\Ford-Fulkerson\\test.txt");

    if (!content.fail())
    {
        int graph[V][V] ;
        string line;
        string delimiter = ",";
        int pos = 0;
        string token;
        int i=0;
        int j=0;
        while (!content.eof())
        {
            content >> line;
            if(j<V && i<V) {
                graph[i][j] = atoi(line.c_str());
                j++;
            }

            else if (i<V) {
                j=0;
                i++;
                graph[i][j] = atoi(line.c_str());
                j++;
            }
            else break;

        }
         for (int i=0; i<V; i++) {
             for (int j=0; j<V; j++) {
                 cout << graph[i][j] << " ";
             }
             cout << endl;
         }
         cout << "Maximum flow is: " << fordFulkerson(graph, 0, 10);
    }
    else cout << "File could not be opened" << endl;
    content.close();

    return 0;

}