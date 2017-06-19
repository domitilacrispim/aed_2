#include<stdio.h>
#include <string.h>
#define tam 100
#define infinito 2147483647
int numVertices(int Grafo[tam][tam]){
	int a=0,b=0,k=0, j=0;
		
	for (a=0;a<tam; a++){
		k=0;
		for(int b=0; b<tam; b++){
			if(Grafo[a][b]==(-1)){
				k++;
			} 
		}
		if(k) j++;
	}
	return j;
}


int grauVertice(int Grafo[tam][tam], int v){
	int y=0, grau=0, n;
	n=numVertices(Grafo);
	if(v>=n){
		return -1;
	}
	for(;y<tam; y++){
		if(Grafo[v][y]!=0 && Grafo[v][y]!=(-1)){
			grau++;
		} 
	}
	return grau;
}



int ehAdjacente ( int BUMBUM[tam][tam], int v1, int v2){
	int n;
	n=numVertices(BUMBUM);
	if(v1>=n || v2>=n) return (-1);
	if( BUMBUM[v1][v2]>0) return 1;
	else return 0;
}



void busca_profunda ( int Grafo[tam][tam], int v, int vis[tam]){
	vis[v]=1;
	for (int i=0; i<numVertices(Grafo); i++){	
		if(!vis[i] && Grafo[v][i]>0){
			busca_profunda(Grafo, i, vis); 
		}
	}
}

void DFS(int Grafo[tam][tam], int v){
	int vis[tam];
	memset(vis, 0, sizeof(int)*tam);
	busca_profunda(Grafo, v, vis);
}

void inicializa_grafo(int Grafo[tam][tam], int v){
	for ( int y=0; y<v; y++){
		for ( int u=0; u<v; u++){
			Grafo[y][u]=(-1);
		}
	}
}

void busca_largura(int Grafo[tam][tam], int v){
	int vis[tam], fila[tam], ini, fim;
	memset(vis, 0, sizeof(vis));
	ini=0; 	fim=0; 
	fila[fim]=v;
	fim++;
	while(fim!=ini){
		ini++;
		for (int i=0; i<numVertices(Grafo); i++){	
			if(!vis[i] && Grafo[v][i]>0){
				//operacao
				fila[fim]=i;
				fim++;				
			} 
		}
	}	
}

int dijkstra(int Grafo[tam][tam], int v, int dis[tam]){
	int s[tam];
	memset(s, 0, sizeof(s));
	memset(dis, infinito, sizeof(int)*tam);
	dis[v]=0;
	s[v]=1;
	for (int y=0; y<numVertices(Grafo); y++){
		if(Grafo[v][y]>0){
			dis[y]=Grafo[v][y];
		}
	}
	int menor=infinito, pos;
	for ( int t=1; t<numVertices(Grafo); t++){
		for(int u=0; u<numVertices(Grafo); u++){
			if(dis[u]<menor && !s[u] && u!=v){
				pos=u;
				menor=dis[u];
			}
		}
		s[pos]=1;
		for(int r=0; r<numVertices(Grafo); r++){
			if(Grafo[pos][r]>0 && dis[r]>(dis[pos]+Grafo[pos][r]) ){
				dis[r]=	(dis[pos]+Grafo[pos][r]);
			}
		}
	}
	return 1;	
}

int main (){
	int grafo[tam][tam], dist[tam]; 
	int a;
	memset(grafo, (0), sizeof(grafo));
	printf("Digite o numero de vertices!");
	scanf("%d", &a);
	inicializa_grafo(grafo, a);
 	grauVertice(grafo, 0);
	
}
