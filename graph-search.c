#include<stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10 // �ִ� ���� ��

typedef struct Node {
	int vertex; // ���� ��ȣ
	struct Node* next; // ���� ��� ������
} Node;

typedef struct Graph {
	int numVertex[MAX_VERTEX]; // ���� ����
	Node* adjList[MAX_VERTEX]; // ���� ����Ʈ (�迭)
} Graph;

Graph* InitializeGraph(Graph* g);
void InsertVertex(Graph* g, int v);
void InsertEdge(Graph* g, int u, int v);
void PrintGraph(Graph* g);
void Quit(Graph* g);

void DepthFirstSearch(Graph* g);
void BreathFirstSearch();

int main(){
    char command;
	Graph* g=NULL;
	int v,u;

    do{
		printf("\n\n");
		printf("---------------[===== [��ΰ�] [2023041054] =====]---------------\n");
		printf("                          Graph Searches                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize Graph     = z                                       \n");
		printf(" Insert Vertex        = v      Insert Edge                  = e \n");
		printf(" Depth First Search   = d      Breath First Search          = b \n");
		printf(" Print Graph          = p      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			g=InitializeGraph(g);
			break;
		case 'q': case 'Q':
			Quit(g);
			break;
		case 'v': case 'V':
			
			printf("Your Vertex = ");
			scanf("%d", &v);
			InsertVertex(g,v);
			break;
		case 'd': case 'D':
			DepthFirstSearch(g);
			break;
		case 'p': case 'P':
			PrintGraph(g);
			break;
		case 'e': case 'E':
			printf("edge1 = ");
			scanf("%d", &u);
			printf("edge2 = ");
			scanf("%d", &v);
			InsertEdge(g,u,v);
			break;
		case 'b': case 'B':
			BreathFirstSearch();
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;
}

Graph* InitializeGraph(Graph* g){
	if(g!=NULL) Quit(g);

	g=(Graph*)malloc(sizeof(Graph));
	for(int i=0;i<MAX_VERTEX;i++){
		g->numVertex[i]=0;
		g->adjList[i]=NULL;
	}
	return g;
}

void InsertVertex(Graph* g, int v){
	if(g==NULL){
		printf("�׷����� �����ϴ�.\n");
		return;
	}
	if(v<0 || v>=MAX_VERTEX || g->numVertex[v]==1){
		printf("error\n");
		return;
	}

	g->numVertex[v]=1;
}

void DepthFirstSearch(Graph* g){
	//start �ε��� ã��
	int start;
	for(int i=0;i<MAX_VERTEX;i++){
		if(g->adjList[i]!=NULL){
			start=i;
			break;
		}
	}

	//DFS�� �� �� ���� ����
	if (g == NULL || start < 0 || start >= MAX_VERTEX) return;
    
    // �湮 ���θ� ǥ���ϴ� �湮 �迭 ����
    int visited[MAX_VERTEX];
	for(int i=0;i<MAX_VERTEX;i++) visited[i]=0;

    // ���� ����
    Node* stack[MAX_VERTEX];
	int top = -1;

	//�湮���� ���� ��忩�� ��
	// visited[i]==1

	// ���� ������ ���ÿ� �����ϰ� �湮 ó��
    stack[++top] = g->adjList[start];
    visited[start] = 1;

    int n=start;
    printf("%d ", start);

    for (int i = start; i < MAX_VERTEX; i++) {
		if(g->adjList[i]!=NULL){
			Node* p = g->adjList[i];
			while (p != NULL) {
                if(visited[p->vertex]==0){
                    visited[p->vertex]=1;
                }
				printf("%d ", p->vertex);
				p = p->next;
			}
		}
	}

    // while(top!=-1) {
    //     Node* current = stack[top--];
    //     printf("%d ", current->vertex);
    //     // if(current->next==NULL) current=g->adjList[current->vertex];
    //     // printf("current=%d, visited[%d]=%d, top=%d\n",current->vertex,n,visited[n],top);

    //     // ���� ����� ��� ���� ��� Ž�� (�������� ���� ��ȣ)
    //     while (current != NULL) {
    //         int v = current->vertex;

    //         // �湮���� ���� ���� ��带 ���ÿ� �ְ� �湮 ó��
    //         if (!visited[v]) {
    //             stack[++top] = g->adjList[v];
    //             visited[v] = 1;
    //         }

    //         // �湮������ ���� ���ÿ� �����ִ� ��� �ǳʶڴ�.
    //         else if (visited[v] == 1 && current->next != NULL) {
    //             current = current->next;
    //             continue;
    //         }

    //         // �湮�߰ų� ������ ���������� ���� ���� �̵�
    //         current = current->next;
    //     }

        // if(current->next==NULL) 
        // for (Node* neighbor = current; neighbor != NULL; neighbor = neighbor->next) {
        //     int v = neighbor->vertex;
        //     n=neighbor->vertex;
            
        //     printf("neighbor=%d, visited[%d]=%d, top=%d\n",neighbor->vertex,n,visited[v],top);
            
        //     // �湮���� ���� ���� ��带 ���ÿ� �ְ� �湮 ó��
        //     if (!visited[v]) { //visited[v]==0 �̸�
        //         stack[++top] = neighbor;
        //         visited[v] = 1;
        //     }else{
        //         --top;
        //     }
        //     printf("neighbor=%d, visited[%d]=%d, top=%d\n",neighbor->vertex,n,visited[v],top);
        // }
        // printf("\n");

        // int flag=0;
        // for(int i=0;i<MAX_VERTEX;i++){
        //     if(visited[i]==1) flag++;
        //     else break;
        // }
        // if(flag==MAX_VERTEX-1) break;

    // }
    // printf("\n\n");
    // for(int i=0;i<MAX_VERTEX;i++) printf("visited[%d]=%d ",i,visited[i]);
}

void PrintGraph(Graph* g){
	if(g==NULL){
		printf("�׷����� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < MAX_VERTEX; i++) {
		if(g->adjList[i]!=NULL){
			Node* p = g->adjList[i];
			printf("���� %d�� ���� ����Ʈ", i);
			while (p != NULL) {
				printf("-> %d", p->vertex);
				p = p->next;
			}
			printf("\n");
		}
	}
}

void InsertEdge(Graph* g, int u, int v){
	if(g==NULL){
		printf("�׷����� �����ϴ�.\n");
		return;
	}
	if(g->numVertex[u]==0 || g->numVertex[v]==0) {
		printf("vertex�� �߰��ϼ���.\n");
		return;
	}
    
	Node* node;
	node=(Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = g->adjList[u];
    g->adjList[u] = node;
	
	Node* node2;
	node2=(Node*)malloc(sizeof(Node));
	node2->vertex = u;
    node2->next = g->adjList[v];
    g->adjList[v] = node2;
}

void BreathFirstSearch(){
	
}

void Quit(Graph* g){
	if(g==NULL){
		printf("�׷����� �����ϴ�.\n");
		return;
	}

	for (int i = 0; i < MAX_VERTEX; i++) {
    Node* temp = g->adjList[i]; // �ӽ� ���� ���
    while (temp != NULL) {
      Node* next = temp->next; // ���� ��带 ���� ���� (���� ����)
      free(temp);
      temp = next;
    }
  }
  free(g);
}

