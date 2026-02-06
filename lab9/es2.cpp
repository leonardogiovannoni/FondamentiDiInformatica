#include <cstring>
#include <iostream>
using namespace std;

const int MAX_QUEUES = 10;

const int MAX_LEN = 20;

struct Job {
    char idx[MAX_LEN + 1];
    int npages;
    Job *next;
};

struct Printer {
    Job *head;
    int len;
    int npages_tot;
};

void printer_init(Printer &p) {
    p.head = nullptr;
    p.len = 0;
    p.npages_tot = 0;
}

bool printer_contains_job(const Printer &p, const char *job_idx) {
    for (Job *scan = p.head; scan != nullptr; scan = scan->next) {
        if (strcmp(scan->idx, job_idx) == 0) {
            return true;
        }
    }
    return false;
}

void printer_push_back(Printer &p, const char *job_idx, int pages) {
    Job *new_job = new Job;
    strcpy(new_job->idx, job_idx);
    new_job->npages = pages;
    new_job->next = nullptr;

    Job *curr = p.head;
    Job *prev = nullptr;

    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        p.head = new_job;
    } else {
        prev->next = new_job;
    }
    p.len++;
    p.npages_tot += pages;
}

int printer_avanza_tempo(Printer &p, int npages) {
    int count = 0;
    while (p.head != nullptr) {
        if (p.head->npages > npages) {
            p.head->npages -= npages;
            p.npages_tot -= npages;
            return count;
        }
        npages -= p.head->npages;
        p.npages_tot -= p.head->npages;

        Job *tmp = p.head;
        p.head = tmp->next;
        delete tmp;
        p.len--;

        count++;
    }
    return count;
}

bool job_idx_valid(const char *s) {
    int len = strlen(s);
    if (len > MAX_LEN) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        char c = s[i];
        bool is_upper = (c >= 'A' && c <= 'Z');
        bool is_lower = (c >= 'a' && c <= 'z');

        bool is_char_valid = is_upper || is_lower;
        if (!is_char_valid) {
            return false;
        }
    }
    return true;
}

struct CentroStampe {
    int len;
    Printer queues[MAX_QUEUES];
};

bool inizializza(CentroStampe &cs, int nqueues) {
    if (nqueues < 1 || nqueues > MAX_QUEUES) {
        return false;
    }
    cs.len = nqueues;
    for (int i = 0; i < nqueues; i++) {
        printer_init(cs.queues[i]);
    }
    return true;
}

bool inserisci(CentroStampe &cs, int q, const char *job_idx, int pages) {
    q--;
    if (q < 0 || q >= cs.len) {
        return false;
    }

    if (!job_idx_valid(job_idx)) {
        return false;
    }

    for(int i = 0; i < cs.len; i++) {
        if (printer_contains_job(cs.queues[i], job_idx)) {
            return false;
        }
    }

    printer_push_back(cs.queues[q], job_idx, pages);
    return true;
}

int meno_carica(CentroStampe &cs) {
    int min_idx = 0;
    int min_pages = cs.queues[0].npages_tot;

    for (int i = 1; i < cs.len; i++) {
        if (cs.queues[i].npages_tot < min_pages) {
            min_pages = cs.queues[i].npages_tot;
            min_idx = i;
        }
    }
    return min_idx + 1;
}

int avanza_tempo(CentroStampe &cs, int nminutes) {
    int total_completed = 0;
    for (int i = 0; i < cs.len; i++) {
        total_completed += printer_avanza_tempo(cs.queues[i], nminutes);
    }
    return total_completed;
}

bool accoda(CentroStampe &cs, const char *job_idx, int pages) {
    int q = meno_carica(cs);
    return inserisci(cs, q, job_idx, pages);
}

void stampa(const CentroStampe &cs) {
    for (int i = 0; i < cs.len; i++) {
        cout << "printer " << (i + 1) << ":";
        Printer p = cs.queues[i];
        if (p.head == nullptr) {
            cout << "[]" << endl;
            continue;
        }
        for (Job *scan = p.head; scan != nullptr; scan = scan->next) {
            cout << "[" << scan->idx << "," << scan->npages << "]";
        }
        cout << endl;
    }
}

int main() {
    CentroStampe c;
    inizializza(c, 2);

    stampa(c);

    inserisci(c, 1, "dd", 10);
    inserisci(c, 1, "fff", 15);

    stampa(c);

    int n = meno_carica(c);
    cout << n << endl;

    accoda(c, "e", 30);
    stampa(c);

    int finiti = avanza_tempo(c, 12);
    cout << finiti << endl;

    stampa(c);
    return 0;
}