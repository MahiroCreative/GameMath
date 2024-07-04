#include "SceneFedo.h"

SceneFedo::SceneFedo():
	Start(0),
	Fedo(false)
{
}

SceneFedo::~SceneFedo()
{
}

void SceneFedo::Init()
{
	Start = 0;
	Fedo = false;
}

void SceneFedo::Update()
{
	//�t�F�[�h�A�E�g������
	if (Fedo == true)
	{
		if (Start >= 0) Start--;
	}
	//�t�F�[�h�C��������
	else if (Fedo == false)
	{
		if (Start >= 0 && 256) Start++;
	}
	
}

void SceneFedo::Draw()
{
	SetDrawBright(Start, Start, Start);
}

void SceneFedo::End()
{
}
