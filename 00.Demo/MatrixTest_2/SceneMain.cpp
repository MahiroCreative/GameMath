#include "SceneMain.h"
#include "DxLib.h"
#include <cmath>

namespace
{
	// カメラの初期座標
	const Vector3 kCameraPos = { 0.0f, 300.0f, -700.0f };

	constexpr float kCameraNear = 200.0f;	// カメラのNear
	constexpr float kCameraFar = 1500.0f;	// カメラのFar

	// プレイヤーの初期座標
	const Vector3 kPlayerPos = { 0.0f,0.0f,0.0f };

	// プレイヤーのスケール
	const Vector3 kPlayerScale = { 0.5f,0.5f,0.5f };
}

SceneMain::SceneMain() :
	m_frameCount(0),
	m_angle(0.0f),
	m_modelHandle(-1),
	m_rotationMat{},
	m_pos{}
{
}

SceneMain::~SceneMain()
{
	MV1DeleteModel(m_modelHandle);
}

void SceneMain::Init()
{
	// カリングの設定
	SetUseBackCulling(true);

	// Zバッファの設定
	SetUseZBuffer3D(true);	// Zバッファを使います
	SetWriteZBuffer3D(true);	// 描画する物体はZバッファにも距離を書き込む

	// カメラの設定
	SetCameraPositionAndTarget_UpVecY(kCameraPos.ToDxLibVector(), VGet(0.0f, 0.0f, 0.0f));
	SetupCamera_Perspective(DX_PI_F / 3.0f);
	SetCameraNearFar(kCameraNear, kCameraFar);

	m_modelHandle = MV1LoadModel("data/Character_Gun.mv1");
	MV1SetScale(m_modelHandle, kPlayerScale.ToDxLibVector());
	MV1SetPosition(m_modelHandle, kPlayerPos.ToDxLibVector());
}

void SceneMain::Update()
{
	m_frameCount++;

	m_angle += 0.02f; // 回転角度を増加

	// Y軸回転行列を作成
	m_rotationMat.RotateY(m_angle);

	// カメラの座標を回転行列で変換
	m_pos = m_rotationMat * kCameraPos;

	// 座標固定でターゲットがY軸回転
	SetCameraPositionAndTarget_UpVecY(kCameraPos.ToDxLibVector(), m_pos.ToDxLibVector());

	if (CheckHitKey(KEY_INPUT_1))
	{
		// 原点を中心にY軸回転
		SetCameraPositionAndTarget_UpVecY(m_pos.ToDxLibVector(), VGet(0.0f, 0.0f, 0.0f));
	}
}

void SceneMain::Draw()
{
	DrawGrid();

	DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	DrawFormatString(0, 16, GetColor(255, 255, 255), "FRAME:%d", m_frameCount);

	DrawFormatString(0, 32, GetColor(255, 255, 255), "X:%f Y:%f Z:%f", m_pos.x, m_pos.y, m_pos.z);

	MV1DrawModel(m_modelHandle);

}

void SceneMain::DrawGrid()
{
	// 直線の始点と終点
	VECTOR startPos;
	VECTOR endPos;

	for (int z = -300; z <= 300; z += 100)
	{
		startPos = VGet(-300.0f, 0.0f, static_cast<float>(z));
		endPos = VGet(300.0f, 0.0f, static_cast<float>(z));
		DrawLine3D(startPos, endPos, 0xff0000);
	}
	for (int x = -300; x <= 300; x += 100)
	{
		startPos = VGet(static_cast<float>(x), 0.0f, -300.0f);
		endPos = VGet(static_cast<float>(x), 0.0f, 300.0f);
		DrawLine3D(startPos, endPos, 0x0000ff);
	}
}
