#include <iostream>

using namespace std;

struct TempLog {
    float *values;
    int len;
};

bool templog_init(TempLog &t, float arr[], int len) {
    if (len <= 0) {
        delete[] arr;
        t.values = nullptr;
        t.len = 0;
        return false;
    }
    t.values = arr;
    t.len = len;
    return true;
}

void templog_destroy(TempLog &t) {
    delete[] t.values;
    t.values = nullptr;
    t.len = 0;
}

void templog_print(const TempLog &t, const char label[]) {
    if (t.len == 0) {
        cout << label << ": [ ]" << endl;
        return;
    }
    cout << label << ": [ ";
    for (int i = 0; i < t.len; i++) {
        cout << t.values[i] << (i < t.len - 1 ? ", " : " ");
    }
    cout << "]" << endl;
}

TempLog templog_filter_high(const TempLog &source, float threshold) {
    int count = 0;
    for (int i = 0; i < source.len; i++) {
        if (source.values[i] > threshold) {
            count++;
        }
    }

    if (count == 0) {
        TempLog empty = {};
        templog_init(empty, nullptr, 0);
        return empty;
    }

    float *new_values = new float[count];

    int j = 0;
    for (int i = 0; i < source.len; i++) {
        if (source.values[i] > threshold) {
            new_values[j] = source.values[i];
            j++;
        }
    }

    TempLog result = {};
    templog_init(result, new_values, count);
    return result;
}

int main() {
    int n = 0;
    cout << "Quante temperature vuoi inserire? ";
    cin >> n;

    float *raw_data = new float[n];
    for (int i = 0; i < n; i++) {
        cout << "Temp " << i << ": ";
        cin >> raw_data[i];
    }

    TempLog daily_log = {};
    if (!templog_init(daily_log, raw_data, n)) {
        templog_destroy(daily_log);
        cout << "Dati non validi!" << endl;
        return 1;
    }

    templog_print(daily_log, "Tutte le temperature");

    float soglia = 0.0f;
    cout << "Inserisci soglia di allarme: ";
    cin >> soglia;

    TempLog alarm_log = templog_filter_high(daily_log, soglia);

    templog_print(alarm_log, "Temperature CRITICHE");

    templog_destroy(alarm_log);
    templog_destroy(daily_log);
    return 0;
}