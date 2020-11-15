/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 * Insert Node Information : for(N) = O(N) => O(N)
 */

/* Solution method : 풀이 방법
 * 1. Compare to twoNode And then if first node eixst Parrent Node , secondNode is son of firstNode. In other words second node exist parrent Node , first Node is son of secondNode
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

struct BaekJoonNode
{
    /* Variable Description(변수 설명 : English , Korean )
    * isExistSunNode : Does the node have child nodes? : 해당 노드는 자식 노드를 가지고 있는가 ?
    * isExistParrentNode : Does the node have Parrent nodes? : 해당 노드는 부모 노드를 가지고 있는가 ?
    * parrendNodeIndex : Array index where the parent node is located. : 부모 노드가 위치하는 배열 인덱스
    * nodeNumber : The number of the current node. : 현재 노드의 번호
    */
    bool isExistSunNode; // Default Value = -1
    bool isExistParrentNode;
    int parrendNodeIndex;
    int nodeNumber;
};

/* Variable Description(변수 설명 : English , Korean )
 * MAX_NODE_COUNT : The maximum number of nodes that make up the tree : 트리를 구성하는 최대 노드 개수
 * baekJoonTree   : Tree : 트리
 */
#define MAX_NODE_COUNT (100001)
BaekJoonNode baekJoonTree[MAX_NODE_COUNT];

int NodeSearch(int nodeNumber)
{
    return 0;
}

/* Function Description(함수 설명 : English , Korean )
 * Function Name : InitBaekJoonNode : 노드 정보 초기화
 * Role : Initalization baekJoon tree node inforamtion : baekJoon 노드 정보 초기화
 */
void InitBaekJoonNode(int nodeCount)
{
    memset(baekJoonTree , 0 , sizeof(int) * nodeCount);
    baekJoonTree[1].parrendNodeIndex = -1;
    baekJoonTree[1].nodeNumber = 1;
    baekJoonTree[1].isExistParrentNode = true;
}

/* Function Description(함수 설명 : English , Korean )
 * Function Name : InsertNodeWithNodeInfor : 전달 받은 노드 정보 입력
 * Role : Compare to two Node Information , and then insert node info in baekJoonNode : 두개 노드 정보 비교후 , 백준 노드에 조건에 맞게 입력
 */
void InsertNodeWithNodeInfor(const int parrentNodeNumber ,
                             const int currentNodeNumber )
{
    if( true == baekJoonTree[currentNodeNumber].isExistParrentNode )
    {
        baekJoonTree[parrentNodeNumber].parrendNodeIndex = currentNodeNumber;
        baekJoonTree[parrentNodeNumber].isExistParrentNode = true;
        baekJoonTree[currentNodeNumber].isExistSunNode = true;
    }
    else
    {
        baekJoonTree[currentNodeNumber].parrendNodeIndex = parrentNodeNumber;
        baekJoonTree[currentNodeNumber].isExistParrentNode = true;
        baekJoonTree[parrentNodeNumber].isExistSunNode = true;
    }
}

int main()
{
    int nodeCount = 0;
    cin >> nodeCount;
    InitBaekJoonNode(nodeCount);
    for( int nodeIndex = 0 ; nodeIndex < nodeCount - 1 ; ++nodeIndex)
    {
        int parrentNodeNumber , currentNodeNumber ;
        cin >> parrentNodeNumber >> currentNodeNumber;
        InsertNodeWithNodeInfor(parrentNodeNumber, currentNodeNumber);
    }
    
    for ( int nodeIndex = 2 ; nodeIndex < nodeCount + 1; ++nodeIndex)
    {
        cout << baekJoonTree[nodeIndex].parrendNodeIndex << endl;
    }
    
    return 0;
}
