//Garima Upadhyay
//220001029
// Given an array of jobs where every job has a deadline and associated profit if the job is
// finished before the deadline. It is also given that every job takes a single unit of time,
// so the minimum possible deadline for any job is 1. Maximize the total profit if jobs are
// scheduled sequentially.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct jobProfit{
    bool operator()(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
        return a.second.first < b.second.first;
    }

};

bool cmp(pair<int,pair<int,int> >a,pair<int,pair<int,int> >b){
    if(a.second.first>=b.second.first){
        return true;
    }
    return false;
}

int jobSeq_greedy(vector<pair<int,pair<int,int> > > job,int n,vector<int>& jobDone){
    sort(job.begin(),job.end(), cmp);
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=min(n-1,job[i].second.second-1);j>=0;j--){
            // cout << j << endl;
            if(jobDone[j]==-1){
                jobDone[j] = job[i].first;
                res += job[i].second.first;
                break;
            }
        }
    }
    
    return res;
};

bool jobDeadlinecmp(pair<int,pair<int,int> > a,pair<int,pair<int,int> > b){
    return a.second.second < b.second.second;
}

int jobSeq_Priorityqueue(vector<pair<int,pair<int,int> > >job,int n){
    sort(job.begin(),job.end(),jobDeadlinecmp);
    vector<pair<int,pair<int,int> > > res;
    int ans = 0;
    priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int>>>,jobProfit> jobmaxHeap;
    for(int i=n-1;i>=0;i--){
        int slot;
        if(i==0){
            slot = job[i].second.second;
        }else{
            slot = job[i].second.second - job[i-1].second.second;
        }
        jobmaxHeap.push(job[i]);
        while(slot>0 && !jobmaxHeap.empty()){
            pair<int,pair<int,int> > job_i = jobmaxHeap.top();
            jobmaxHeap.pop();
            slot--;
            res.push_back(job_i);
            ans+=job_i.second.first;
        }
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<pair<int,pair<int,int> > >job;
    for(int i=0;i<n;i++){
        int deadLine, profit;
        cin >> deadLine >> profit;
        job.push_back(make_pair(i,make_pair(profit,deadLine)));
    }
    vector<int> jobDone(n,-1);
    int profitGreedy = jobSeq_greedy(job,n,jobDone);
    cout << "Profit objtained by greedy method is : " << profitGreedy << endl;
    int profitPriorityQueue = jobSeq_Priorityqueue(job,n);
    cout << "Profit obtained by priority queue is : " << profitPriorityQueue << endl;
    
}