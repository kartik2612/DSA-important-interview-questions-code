#include<bits/stdc++.h>
using namespace std;

class cir_queue
{
    public:
    int front;
    int rear;
    int size;
    int *arr;
    
    int isFULL(cir_queue *cq)
    {
        if((cq->front==0 && cq->rear==cq->size-1) || (cq->front==(cq->rear+1)%cq->size))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    int isEmpty(cir_queue *cq)
    {
        if(cq->rear==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    void enqueue(cir_queue *cq,int x)
    {
        if(isFULL(cq))
        {
            cout<<"circular queue is full"<<endl;
        }
        else
        {
            cq->rear=(cq->rear+1)%cq->size;
            cq->arr[cq->rear]=x;
            cout<<"enqueued successfully "<<x<<endl;
        }
    }
    
    int dequeue(cir_queue *cq)
    {
        if(isEmpty(cq))
        {
            cout<<"circular queue is empty"<<endl;
        }
        else
        {
            cq->front=(cq->front+1)%cq->size;
            int temp=cq->arr[cq->front];
            return temp;
        }
    }
    
    void display(cir_queue *cq)
    {
        for(int i=front+1;i<=rear;(i+1)%cq->size)
        {
            cout<<cq->arr[i]<<" ";
        }
    }
};

int main()
{
    cir_queue *cq=new cir_queue();
    
    cq->front=-1;
    cq->rear=-1;
    cq->size=100;
    cq->arr=new int[cq->size];
    
    cq->enqueue(cq,1);
    cq->enqueue(cq,2);
    cq->enqueue(cq,3);
    cq->enqueue(cq,4);
    
    cout<<"the dequeued element is "<<cq->dequeue(cq)<<endl;
    
    
    return 0;
}
