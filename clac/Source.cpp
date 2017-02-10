#include<stdio.h>


//계산식 (2017.2.5 기준) (공격력)*((1+플스+PVE+여관+인게임)*(1+진형)+((플스+PVE+여관)*(인게임)*진형+펫))*(1+피증류)*(1+치뎀증)*(1+약뎀증)*(120/(100+방어력))*스킬계수*(~인기데미지)


float attack_point, pvpattack, player_point, in_point, mode_point, damege_point, critcal_point, small_attack, block_power, block_down, block_up, skill_point, block_final;
int pvepvp, critcal_true, small_true;
float true_damege;
float true_block;
float damege, K, A;


void input()
{
	printf("80%% = 0.8, 180%% = 1.8 등으로 적어 주세요\n");
	printf("pve = 1 , pve = 2 :");
	scanf_s("%d", &pvepvp);
	printf("\n공격력 :");
	scanf_s("%f", &attack_point);
	printf("\n플스로 증가된 공 :");
	scanf_s("%f", &player_point);
	printf("\n증가된 공 :");
	printf("\nPVEorPVP로 증가된 공");
	scanf_s("%f", &pvpattack);
	scanf_s("%f", &in_point);
	printf("\n진형으로 증가된 공 :");
	scanf_s("%f", &mode_point);
	printf("\n피증 :");
	scanf_s("%f", &damege_point);
	printf("\n치뎀증 :");
	scanf_s("%f", &critcal_point);
	printf("\n약뎀증 :");
	scanf_s("%f", &small_attack);
	printf("\n방어력 :");
	scanf_s("%f", &block_power);
	printf("\n방감 :");
	scanf_s("%f", &block_down);
	printf("\n방증 :");
	scanf_s("%f", &block_up);
	printf("\n스킬계수(평타는 1) :");
	scanf_s("%f", &skill_point);
	printf("\n 약공 여부 (터졌으면 1, 아니면 0) : ");
	scanf_s("%d", &small_true);
	printf("\n 치명타 여부 (터졌으면 1, 아니면 0, 막기면 -1) : ");
	scanf_s("%d", &critcal_true);
	printf("\n 실제 데미지 : ");
	scanf_s("%f", &true_damege);
	
}

void re_calc()
{
	true_block = (120 * A) - (100 * true_damege);
	true_block /= ((0.6)*K*true_damege);
}

int main()
{
	input();
	A = (attack_point * (1 + in_point + player_point) * (1 + mode_point) + (in_point*player_point*mode_point));
	A *= (1 + damege_point);
	if (critcal_true == 1) A *= (1 + critcal_point);
	else if (critcal_true == -1) A /= 2;

	if (small_true == 1) A *= (1 + small_attack);

	A *= skill_point;
	K =(1 + block_up - block_down);
	block_final = 120 /(100+ (0.6*block_power*K));
	damege = A * block_final;
	re_calc();
	printf("\n이론데미지 : %f\n", damege);
	printf("역보정 후 방어력 : %f", true_block);
}