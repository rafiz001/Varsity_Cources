#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
class properties {
public:
  int PID;
  float AT;  // arrival time
  float BT;  // burst time
  float WT;  // waiting time
  float CT;  // completion time
  float RT;  // remaining time
  float TAT; // turn around time
};
bool cmpr(const properties a, const properties b) { return a.AT < b.AT; }
float fcfs(properties e[], int n) {
  
  printf("ID\tAT\tBT\tWT\tCT\tTAT\n");
  float total = 0, totWT = 0, totTAT = 0;
  for (int i = 0; i < n; i++) {
    if (total < e[i].AT) {
      total = e[i].AT;
    }
    e[i].WT = total - e[i].AT;
    e[i].TAT = e[i].WT + e[i].BT;
    e[i].CT = total + e[i].BT;
    printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", e[i].PID, e[i].AT, e[i].BT,
           e[i].WT, e[i].CT, e[i].TAT);
    total = e[i].CT;
    totWT += e[i].WT;
    totTAT += e[i].TAT;
  }
  float avgTAT = totTAT / n;
  float avgWT = totWT / n;
  printf("For FCFS Avg WT= %.2f Avg TAT= %.2f\n", avgWT, avgTAT);
  return (avgWT + avgTAT) / 2.0;
}
float sjf(properties p[], int n) {
  float total = 0, totWT = 0, totTAT = 0;
  for (;;) {
    int minBurstId = -1;
    float minBurst = MAXFLOAT;
    for (int i = 0; i < n; i++) {
      // checking which one is arrived and the remaining time is not 0
      if (p[i].AT <= total && p[i].RT > 0) {
        // checking which one has minimum burst time
        if (p[i].RT < minBurst) {
          minBurst = p[i].RT;
          minBurstId = i;
        }
      }
    }

    // checking whether any proccess has a remaining time
    bool isThereAnyProcess = false;
    for (int i = 0; i < n; i++) {
      if (p[i].RT != 0) {
        isThereAnyProcess = true;
        break;
      }
    }
    if (!isThereAnyProcess) {
      break;
    } else if (minBurstId == -1) { // idle state
      total += 1;
      continue;
    }

    // remaining time
    if (p[minBurstId].RT < 1) {
      total += p[minBurstId].RT;
      p[minBurstId].RT = 0;
    } else {
      total += 1;
      p[minBurstId].RT -= 1;
    }
    // TAT,WT, CT
    if (p[minBurstId].RT == 0) {
      p[minBurstId].CT = total;
      p[minBurstId].WT = total - p[minBurstId].BT -
                         p[minBurstId].AT; // wt=ct-bt-at for preemtive
      p[minBurstId].TAT = p[minBurstId].BT + p[minBurstId].WT; // tat=bt+wt
      totWT += p[minBurstId].WT;
      totTAT += p[minBurstId].TAT;
    }
  }
  float avgTAT = totTAT / n;
  float avgWT = totWT / n;
  // printing table
  printf("ID\tAT\tBT\tWT\tCT\tTAT\tRT\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p[i].PID, p[i].AT,
           p[i].BT, p[i].WT, p[i].CT, p[i].TAT, p[i].RT);
  }
  printf("For SJF Avg WT= %.2f Avg TAT= %.2f\n", avgWT, avgTAT);

  return (avgTAT + avgWT) / 2;
}
int main() {
  int n;
  scanf("%d", &n);

  properties entries[n];
  printf("Input 0-%d Arrival time and Burst time\n", n - 1);
  for (int i = 0; i < n; i++) {
    entries[i].PID = i;
    scanf("%f %f", &entries[i].AT, &entries[i].BT);
    entries[i].RT = entries[i].BT;
  }
  sort(entries, entries + n, cmpr);
 
  float fcfs_score = fcfs(entries, n);
  float sjf_score = sjf(entries, n);
  if (fcfs_score > sjf_score)
    printf("Here, sjf is %.2f times faster than fcfs\n",
           fcfs_score / sjf_score);
  else
    printf("Here, fcfs is %.2f times faster than sjf\n",
           sjf_score / fcfs_score);
}
