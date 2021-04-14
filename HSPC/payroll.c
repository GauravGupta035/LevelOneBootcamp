#include <stdio.h>
#include <string.h>

struct WorkerWage
{
    char name[100];
    int minutes;
    float hours;
    float hourlyWage;
    float grossPay;
};
typedef struct WorkerWage Worker;

Worker input_one_NameWage()
{
    Worker worker;
    scanf("%s %f", &worker.name, &worker.hourlyWage);

    return worker;
}

int find_worker(int n, Worker workers[n], char name[])
{
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(name, workers[i].name))
            return i;
    }

    return 0;
}

void input_n_NameWage(int n, Worker workers[n])
{
    for (int i = 0; i < n; i++)
        workers[i] = input_one_NameWage();
}

void input_timeCards(int totalWorkers, Worker workers[totalWorkers])
{
    int noOfEntries, min, index;
    char name[100];

    scanf("%d", &noOfEntries);

    for (int i = 0; i < noOfEntries; i++)
    {
        scanf("%s", &name);
        index = find_worker(totalWorkers, workers, name);
        scanf("%d", &min);
        workers[index].minutes += min;
    }
}

float compute_hours(float minutes)
{
    return minutes / 60;
}

void compute_one_grossPay(Worker *worker)
{
    worker->hours = compute_hours(worker->minutes);
    
    if (worker->hours <= 40.00)
        worker->grossPay = worker->hourlyWage * worker->hours;
    else
        worker->grossPay = (worker->hourlyWage * 40.00) + (1.5 * (worker->hourlyWage * (worker->hours - 40.00)));
}

void compute_n_grossPay(int n, Worker workers[n])
{
    for (int i = 0; i < n; i++)
        compute_one_grossPay(&workers[i]);
}

void output_one_worker(Worker worker)
{
    printf("%s: %.2f hours, $%.2f\n", worker.name, worker.hours, worker.grossPay);
}

void output_n_workers(int n, Worker workers[n])
{
    for (int i = 0; i < n; i++)
        output_one_worker(workers[i]);
}

int main()
{
    int n;
    scanf("%d", &n);
    Worker workers[n];
    input_n_NameWage(n, workers);
    input_timeCards(n, workers);
    compute_n_grossPay(n, workers);
    output_n_workers(n, workers);

    return 0;
}