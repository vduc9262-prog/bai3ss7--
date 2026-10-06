#include <stdio.h>
#include <math.h>

struct SmartDeviceFlat {
    double powerMeasured;
    double voltage;
    double current;
    int status;
    int operatingMinutes;
};

int main() {
    struct SmartDeviceFlat device;
    double Pcalc, kWh;

    printf("Nhap dien ap (V): ");
    scanf("%lf", &device.voltage);
    printf("Nhap dong dien (A): ");
    scanf("%lf", &device.current);
    printf("Nhap cong suat do duoc (W): ");
    scanf("%lf", &device.powerMeasured);
    printf("Nhap trang thai thiet bi (0-Tat,1-Bat): ");
    scanf("%d", &device.status);
    printf("Nhap thoi gian hoat dong (phut): ");
    scanf("%d", &device.operatingMinutes);

    if (device.voltage <= 0 || device.current < 0 || device.operatingMinutes < 0 || (device.status != 0 && device.status != 1)) {
        printf("LOI: Du lieu khong hop le.\n");
        return 0;
    }

    Pcalc = device.voltage * device.current;

    if (fabs(device.powerMeasured - Pcalc) > 0.05 * Pcalc) {
        printf("CANH BAO: Cam bien cong suat bao sai lech.\n");
    }

    if (device.current > 30.0 || device.powerMeasured > 6600.0) {
        printf("CANH BAO: QUA TAI NGUY HIEM!\n");
    }

    if (device.status == 0 && device.current > 0.05) {
        printf("CANH BAO: RO RI DIEN HOAC TAI AN.\n");
    }

    kWh = (device.powerMeasured * (device.operatingMinutes / 60.0)) / 1000.0;

    printf("=== BAO CAO THIET BI ===\n");
    printf("Dien ap: %.2f V\n", device.voltage);
    printf("Dong dien: %.2f A\n", device.current);
    printf("Cong suat do duoc: %.2f W\n", device.powerMeasured);
    printf("Trang thai: %s\n", device.status ? "BAT" : "TAT");
    printf("Thoi gian hoat dong: %d phut\n", device.operatingMinutes);
    printf("Dien nang tieu thu: %.4f kWh\n", kWh);

    return 0;
}
