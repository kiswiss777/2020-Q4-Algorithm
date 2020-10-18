#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

/* Variable Description(변수 설명 : English , Korean )
 * MAX_APPLICATIN_NUMBER : Maximum number of applicants : 최대 지원자 수
 * gradeList : Grade rank table(Document , Interview ) : 성적 순위 테이블 ( 서류 , 면접 )
 */

#define MAX_APPLICATIN_NUMBER (100000)
pair<int,int> gradeList[MAX_APPLICATIN_NUMBER];

/* Complexity : 복잡도
 * Note: Input is not included in the complexity. : 입력 로직은 복잡도에 포함하지 않는다.
 * Sort(NLogN) + for(N) = O(NLogN)
 */

/* Solution method : 풀이 방법
 * 1. Asending Sorting is performed in the order of document grades.
    ->서류면접 성적 순으로 정렬 작업을 진행한다.
 * 2. The comparison is conducted based on the interview rank of the successful applicant with the highest document rank.
    ->가장 높은 서류 성적을 가진 지원자의 면접 등수를 기반으로 비교 작업을 진행한다.
 */


int main()
{
    /* Variable Description(변수 설명 : English , Korean )
     * numberOfApplicant = numberOfApplicant : 지원자 수
     */
    int testCase = 0;
    int numberOfApplicant = 0 ;
    
    cin >> testCase;
    for( int testIndex = 0 ; testIndex < testCase ; ++testIndex)
    {
        cin >> numberOfApplicant;
        for( int applicantIndex = 0 ; applicantIndex < numberOfApplicant ; ++ applicantIndex)
        {
            int documentGrade , interviewGrade;
            cin >> documentGrade >> interviewGrade;
            gradeList[applicantIndex].first = documentGrade;
            gradeList[applicantIndex].second = interviewGrade;
        }
        
        sort( gradeList , gradeList + numberOfApplicant);
        /* Variable Description(변수 설명 : English , Korean )
        * numberOfSueccessApplicant = numberOfSueccessApplicant : 합격자 수
        * tempCompareInterviewGrade = Interview ranks of those who have passed the highest document score.
        */
        int numberOfSueccessApplicant = 1;
        int tempCompareInterviewGrade = gradeList[0].second;
        
        for( int applicantIndex = 1 ; applicantIndex < numberOfApplicant ; ++ applicantIndex)
        {
            if( tempCompareInterviewGrade > gradeList[applicantIndex].second)
            {
                numberOfSueccessApplicant++;
                tempCompareInterviewGrade = gradeList[applicantIndex].second;
            }
        }
        
        cout << numberOfSueccessApplicant << endl;
    }
    return 0;
}
