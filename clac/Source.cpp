#include<stdio.h>


//���� (2017.2.5 ����) (���ݷ�)*((1+�ý�+PVE+����+�ΰ���)*(1+����)+((�ý�+PVE+����)*(�ΰ���)*����+��))*(1+������)*(1+ġ����)*(1+�൩��)*(120/(100+����))*��ų���*(~�αⵥ����)


float attack_point, pvpattack, player_point, in_point, mode_point, damege_point, critcal_point, small_attack, block_power, block_down, block_up, skill_point, block_final, motal_attack, pet_attack, peo_attack;
int pvepvp, critcal_true, small_true;
float true_damege;
float true_block;
float damege, K, A;


void input()
{
	printf("80%% = 0.8, 180%% = 1.8 ������ ���� �ּ���\n");
	printf("pve = 1 , pvp = 2 :");
	scanf_s("%d", &pvepvp);
	printf("\n���ݷ� :");
	scanf_s("%f", &attack_point);
	printf("\n�ý��� ������ �� :");
	scanf_s("%f", &player_point);
	printf("\nPVEorPVP�� ������ �� :");
	scanf_s("%f", &pvpattack);
	printf("\n�ΰ������� ������ ��(���ϸ� �нú�, �鰢 ������) :");
	scanf_s("%f", &in_point);
	printf("\n�������� ������ �� :");
	scanf_s("%f", &mode_point);
	printf("\n�������� ������ �� :");
	scanf_s("%d", &motal_attack);
	printf("\n������ ������ �� :");
	scanf_s("%d", &pet_attack);
	printf("\n���� :");
	scanf_s("%f", &damege_point);
	printf("\nġ���� :");
	scanf_s("%f", &critcal_point);
	printf("\n�൩�� :");
	scanf_s("%f", &small_attack);
	printf("\n���� :");
	scanf_s("%f", &block_power);
	printf("\n�氨 :");
	scanf_s("%f", &block_down);
	printf("\n���� :");
	scanf_s("%f", &block_up);
	printf("\nx�α� ������ ���� :");
	scanf_s("%d", &peo_attack);
	printf("\n��ų���(��Ÿ�� 1) :");
	scanf_s("%f", &skill_point);
	printf("\n ��� ���� (�������� 1, �ƴϸ� 0) : ");
	scanf_s("%d", &small_true);
	printf("\n ġ��Ÿ ���� (�������� 1, �ƴϸ� 0, ����� -1) : ");
	scanf_s("%d", &critcal_true);
	printf("\n ���� ������(���� ������� ���� ������ ��길 �� ��� 0) :");
	scanf_s("%f", &true_damege);
	
}

void re_calc()
{
	true_block = (120 * A) - (100 * true_damege);
	true_block /= ((0.6)*K*true_damege);
}
//���� (2017.2.5 ����) (���ݷ�)*((1+�ý�+PVE+����+�ΰ���)*(1+����)+((�ý�+PVE+����)*(�ΰ���)*����+��))*(1+������)*(1+ġ����)*(1+�൩��)*(120/(100+����))*��ų���*(~�αⵥ����)
int main()
{
	input();
	A = (attack_point * (1 + in_point + player_point + pvpattack + motal_attack) * (1 + mode_point) + ((player_point+pvpattack+motal_attack)*in_point*mode_point+pet_attack));
	A *= (1 + damege_point);
	if (critcal_true == 1) A *= (1 + critcal_point);
	else if (critcal_true == -1) A /= 2;

	if (small_true == 1) A *= (1 + small_attack);

	A *= skill_point;
	A *= (peo_attack+1);
	K =(1 + block_up - block_down);
	if(pvepvp==1)  block_final = 120 / (100 + (block_power*K));
	else if (pvepvp==2) block_final = 120 /(100+ (0.6*block_power*K));
	damege = A * block_final;
	
	printf("\n�̷е����� : %f\n", damege);
	if (true_damege != 0) 
	{
		re_calc();
		printf("������ �� ���� : %f", true_block);
	}
}