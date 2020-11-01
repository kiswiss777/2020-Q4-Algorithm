#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

/* Variable Description(변수 설명 : English , Korean )
 * MAX_VERTEX_COUNT : max vertex count : 최대 정점 개수
 * verTexCount : Input vertext coubt : 입력 된 정점 개수
 * ROUTE_GRAPH_VISIT : check visit falg on current route : 현재 경로에 방문하였는지에 대한 비트 플래그
 * ROUTE_GRAPH : route graph: 경로 그래프
 */

#define MAX_VERTEX_COUNT (101)

int verTexCount = 0;
int ROUTE_GRAPH_VISIT[MAX_VERTEX_COUNT] = {0};
int ROUTE_GRAPH[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT] = {0};
/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 *
 */

/* Solution method : 풀이 방법
 * 1. DFS ( N^2 ) = O(N^2)
 */

void RouteDFS(int currLocate)
{
    for(int k = 0 ; k <verTexCount ; ++k)
    {
        if(0 != ROUTE_GRAPH[currLocate][k]
           && 0 == ROUTE_GRAPH_VISIT[k])
        {
            ROUTE_GRAPH_VISIT[k]++;
            RouteDFS(k);
        }
    }
}

void FindRoute()
{
    for( int i = 0 ; i<verTexCount ; ++i)
    {
        memset(ROUTE_GRAPH_VISIT, 0 ,sizeof(int)*verTexCount);
        RouteDFS(i);
        
        for(int j = 0 ; j < verTexCount ; j++ )
        {
            if(0 != ROUTE_GRAPH_VISIT[j])
            {
                ROUTE_GRAPH[i][j] = 1;
            }
        }
    }
}

void SetGraphData()
{
    for(int i = 0 ; i < verTexCount ; i++)
    {
        for(int j = 0; j< verTexCount ; j++)
        {
            cin >> ROUTE_GRAPH[i][j] ;
        }
    }
}


void PrintRoute()
{
    for(int i = 0 ; i < verTexCount ; i++)
       {
           for(int j = 0; j<verTexCount ; j++)
           {
               cout << ROUTE_GRAPH[i][j] << " " ;
           }
           cout << endl;
       }
}

int main()
{
    cin >> verTexCount;
    SetGraphData();
    FindRoute();
    PrintRoute();
}
