#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	struct Node * next, *pre;
	char data;
};

struct Node * head;
struct Node * last;
void s_popcheck();
void s_popcheck2();
void s_push();
void s_push2();
void s_clear();
bool first=true;
bool fail=false;

void order(char glho){
	if(glho=='('){
		s_push();
		return;
	}
	if(glho=='['){
		s_push2();
		return;
	}
	if(glho==')'){
		s_popcheck();
		return;
	}
	if(glho==']'){
		s_popcheck2();
		return;
	}
}

void nojam4949(){
	for(;;){
		int end = 0;
		char glho;
		while(1){
			scanf("%1c",&glho);
			order(glho);
			if(glho=='.') break;
			if(glho!='\n') end++;
		}
		if(end==0)return;
		s_clear();
		if(fail){
			printf("NO\n");
			fail=false;
		}else{
			printf("YES\n");
		}
		printf("%d\n",end);
	}
}

int main(){
	nojam4949();
}

void s_push(){
	struct Node * node;
	node = malloc(sizeof(struct Node));
	if(first){
		node->pre = NULL;
		node->next = NULL;
		node->data = '(';
		head=node;
		last=node;
		first=false;
	}else{
		node->pre = last;
		node->data = '(';
		node->next = NULL;
		last = node;
	}
}
void s_push2(){
	struct Node * node;
	node = malloc(sizeof(struct Node));
	if(first){
		node->pre = NULL;
		node->next = NULL;
		node->data = '[';
		head=node;
		last=node;
		first=false;
	}else{
		node->pre = last;
		node->data = '[';
		node->next = NULL;
		last = node;
	}

}
void s_popcheck(){
	if(first){
		fail=true;
		return;
	}
	struct Node * garbege=last;
	if(garbege->data=='['){
		fail=true;
		return;
	}
	if(garbege->pre==NULL){
		head=NULL;
		last=NULL;
		free(garbege);
		first=true;
	}else{
		garbege->pre->next=NULL;
		last=garbege->pre;
		free(garbege);
	}
}
void s_popcheck2(){
	if(first){
		fail=true;
		return;
	}
	struct Node * garbege=last;
	if(garbege->data=='('){
		fail=true;
		return;
	}
	if(garbege->pre==NULL){
		head=NULL;
		last=NULL;
		free(garbege);
		first=true;
	}else{
		garbege->pre->next=NULL;
		last=garbege->pre;
		free(garbege);
	}
}
void s_clear(){
	if(head==NULL){
		return;
	}
	struct Node * tracker;
	tracker=head;
	head=NULL;
	last=NULL;
	if(first){
		return;
	}else{
		while(tracker->next!=NULL){
			struct Node * garbege;
			garbege=tracker;
			tracker=tracker->next;
			free(garbege);
		}
		fail=true;
	}
	first=true;
}
