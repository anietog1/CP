#include <iostream>
#include <string>

using namespace std;
int tc, n;
string map[110];
bool visited[110][110];

void clean(){
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      visited[i][j] = false;
}

void fillship(int i, int j){
  if(i < 0 || j < 0 || i >= n || j >= n)
    return;

  if(visited[i][j])
    return;

  char curr = map[i][j];
  if(!(curr == 'x' || curr == '@'))
    return;
  
  visited[i][j] = true;

  fillship(i+1,j);
  fillship(i-1,j);

  fillship(i, j+1);
  fillship(i, j-1);
}

int main(){
  cin >> tc;
  for(int ctc=1;ctc<=tc;++ctc){
    cin >> n;
    
    clean();
    
    for(int i=0;i<n;++i)
      cin >> map[i];
    
    int count = 0;
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
	if(!visited[i][j] && map[i][j] == 'x'){
	  ++count;
	  fillship(i, j);
	}
    
    cout << "Case " << ctc << ": " << count << endl;
  }
}
