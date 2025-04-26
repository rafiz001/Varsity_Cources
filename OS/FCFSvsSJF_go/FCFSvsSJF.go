package main

import (
	"fmt"
	"math"
	"sort"
)

type properties struct {
	PID int
	AT  float64 //arrival time
	BT  float64 //burst time
	WT  float64 //waiting time
	TAT float64 //turn around time
	CT  float64 //completion time
	RT  float64 //remaining time
}

func fcfs(e []properties, n int) (score float64) {
	fmt.Printf("ID\tAT\tBT\tWT\tCT\tTAT\n")
	total, totWT, totTAT := 0.0, 0.0, 0.0
	for i := range n {
		if total < e[i].AT {
			total = e[i].AT
		}
		e[i].WT = total - e[i].AT
		e[i].TAT = e[i].WT + e[i].BT
		e[i].CT = total + e[i].BT
		fmt.Printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", e[i].PID+1, e[i].AT, e[i].BT, e[i].WT, e[i].CT, e[i].TAT)
		total = e[i].CT
		totWT += e[i].WT
		totTAT += e[i].TAT
	}
	avgTAT := totTAT / float64(n)
	avgWT := totWT / float64(n)
	fmt.Printf("For FCFS Avg WT= %.2f Avg TAT= %.2f\n", avgWT, avgTAT)
	return (avgWT + avgTAT) / 2.0
}

func sjf(p []properties, n int) (score float64) {

	total, totWT, totTAT := 0.0, 0.0, 0.0
	for {
		minBurstId, minBurst := -1, math.MaxFloat64
		for i := range n {
			//checking which one is arrived and the remaining time is not 0
			if p[i].AT <= total && p[i].RT > 0 {
				//checking which one has minimum burst time
				if p[i].RT < minBurst {
					minBurst = p[i].RT
					minBurstId = i

				}
			}

		}
		//checking whether any proccess has a remaining time
		isThereAnyProcess := false
		for i := range n {
			if p[i].RT != 0 {
				isThereAnyProcess = true
				break
			}
		}
		if !isThereAnyProcess {
			break
		} else if minBurstId == -1 { //idle state
			total += 1
			continue
		}

		//remaining time
		if p[minBurstId].RT < 1 {
			total += p[minBurstId].RT
			p[minBurstId].RT = 0
		} else {
			total += 1
			p[minBurstId].RT -= 1
		}
		//TAT,WT, CT
		if p[minBurstId].RT == 0 {
			p[minBurstId].CT = total
			p[minBurstId].WT = total - p[minBurstId].BT - p[minBurstId].AT //wt=ct-bt-at for preemtive
			p[minBurstId].TAT = p[minBurstId].BT + p[minBurstId].WT        //tat=bt+wt
			totWT += p[minBurstId].WT
			totTAT += p[minBurstId].TAT
		}

	}
	avgTAT := totTAT / float64(n)
	avgWT := totWT / float64(n)
	//printing table
	fmt.Printf("ID\tAT\tBT\tWT\tCT\tTAT\tRT\n")
	for i := range n {
		fmt.Printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p[i].PID+1, p[i].AT, p[i].BT, p[i].WT, p[i].CT, p[i].TAT, p[i].RT)
	}
	fmt.Printf("For SJF Avg WT= %.2f Avg TAT= %.2f\n", avgWT, avgTAT)

	return (avgTAT + avgWT) / 2
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	entries := make([]properties, n)
	fmt.Printf("Input 0-%d Arrival time and Burst time\n", n-1)
	for i := range n {
		entries[i].PID = i
		fmt.Scanf("%f %f", &entries[i].AT, &entries[i].BT)
		entries[i].RT = entries[i].BT
	}
	sort.SliceStable(entries, func(i, j int) bool {
		return entries[i].AT < entries[j].AT
	})
	fcfs_score := fcfs(entries, n)
	sjf_score := sjf(entries, n)
	if fcfs_score > sjf_score {
		fmt.Printf("Here, sjf is %.2f times faster than fcfs\n", fcfs_score/sjf_score)
	} else {
		fmt.Printf("Here, fcfs is %.2f times faster than sjf\n", sjf_score/fcfs_score)
	}
}
