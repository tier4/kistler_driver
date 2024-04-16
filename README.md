# Kistler ROS Driver

This is ROS Driver for Non-contact optical sensors Correvit S-Motion DTI, standard / 2055A.

Kistler official page of 2055A(https://www.kistler.com/JP/ja/cp/non-contact-optical-sensors-correvit-s-motion-dti-2055a/P0001154)

# CAN Communication Specification

| CAN ID | Description          | Date Definition                                       | Note |
| ------ | -------------------- | ----------------------------------------------------- | ---- |
| 0x07E0 | Vel_Angle            | VelX <br> VelY <br> Vel <br> Angle                    | 縦方向速度 - 光学的速度とIMU信号から生成される<br>横方向速度 - 光学的速度とIMU信号から生成される<br>VelXとVelYから算出して得られる速度<br>車両移動方向と車両X軸との角度, VelXとVelYから算出|
| 0x07E1 | Distance             | Distance                                              | Velを組み入れて算出される累積距離|
| 0x07E2 | Pitch_Roll           | Pitch <br> Roll <br> Timestamp <br> Radius            | 水平座標系とボディ座標系との角度, 水平Y軸まわりの回転<br>水平座標系とボディ座標系との角度, ボディX軸まわりの回転<br>プロセッササイクルカウント, 2ms毎に1ずつ増加<br> パス半径, VelXとAngVelZ_bodyから算出|
| 0x07E3 | AccHor_AccCBody      | AccX_hor <br> AccY_hor <br> AccZ_hor <br> Acc_C_body  | 縦方向加速度 - 重力による影響が除去されている<br>横方向加速度 - 重力による影響が除去されている<br>垂直方向加速度<br>VelXとAngVelZ_bodyから算出される横方向加速 - 重力による影響が除去されている|
| 0x07E4 | AngVelHor            | AngVelX_hor <br> AngVelY_hor <br> AngVelZ_hor         | X軸まわりの角速度 <br> Y軸まわりの角速度, ピッチレート<br>Z軸まわりの角速度, ヨーレート|
| 0x07E5 | Correvit             | VelX_cor <br> VelY_cor <br> Vel_cor <br> Angle_cor    | Raw縦方向速度 - 光学式(Correvit)測定のみ<br>横方向速度 - 光学式(Correvit)測定のみ<br>VelX_corとVelY_corから算出して得られる速度<br>車両移動方向と車両X軸との角度, VelX_cor と VelY_cor から算出|
| 0x07E6 | AccBody              | AccX_body <br> AccY_body <br> AccZ_body               | 縦方向加速度 <br> 横方向加速度 <br> 垂直方向加速度 |
| 0x07E7 | AngVelBody           | AngVelX_body <br> AngVelY_body <br> AngVelZ_body      | X軸まわりの角速度, ロールレート<br>Y軸まわりの角速度<br>Z軸まわりの角速度|
| 0x07E8 | Coordinates          | Latitude <br> Longitude                               | GPS緯度位置 <br> GPS経度位置 |
| 0x07E9 | Additional_Sat_Info  | TimeOfWeek <br> Track <br> Height                     | GPS時(UCT) <br> GPS座標系の移動方向, 0: 北, 90: 東, 180: 南, 270: 西<br> 海抜高度|
| 0x07EA | Inputs               | AnaIn1 <br> AngIn2 <br> DigIn                         | アナログ入力1 <br> アナログ入力2 <br> デジタル入力 |
| 0x07EB | Status               | SensorID <br> Temperature <br> LampCurrent <br> FilterSetting <br> NumOfSta <br> STST <br> FilterOffOn <br> LampCurrentControl <br> TemperatureOK <br> HeadStatus <br> AngleSwitchedOff <br> Direction <br> SatFixed <br> AngVelCorrection <br> DirectionMotion <br> DirectionMounting <br> DirectionHeadIsValid <br> DirectionHead | [CAN バス]ページのKiCenterで設定可能なユーザー固有番号 <br> センサヘッド内の温度 <br> 消費電流 <br> フィルタが有効になっている場合, 平均化のために使用されるサンプル数 <br> GPS用に使用される衛星数 <br> 0-センサ作動; 1-停止, センサが動きを検出しない <br> 0-移動平均フィルタが有効になっていない; 1-移動平均フィルタが有効になっている <br> 0-ハロゲンランプの電流制御が作動していない; 1-ハロゲンランプの電流制御が作動している <br> 0-センサヘッドの温度が高すぎる(ランプがスイッチオフになる); 1-センサヘッドの温度が80°C以下 <br> 0-センサヘッドが接続されていない; 1-センサヘッドが接続されている <br> 0-角度出力が有効(速度が設定限度値以上); 1-角度出力が0(速度が設定限度値以下) <br> DirectionMotion*DirectionMountingの結果として得られる方向 <br> 0-GPS位置の評価に使用可能な衛星数が十分でない; 1-GPS位置の評価に使用可能な衛星数が十分 <br> 0-AngVel信号のオフセット補正なし; 1-停止が検出され, 自動オフセット補正が有効 <br> 0-Motion アルゴリズムによる速度の符号がマイナス; 1-Motion アルゴリズムによる速度の符号がプラス <br> 0-取付け方向が **Reverse(リバース)** に設定されている; 1-取付け方向が **Normal(標準)** に設定されている <br>0-センサヘッドからの方向信号が有効と検知されていない; 1-センサヘッドからの方向信号が有効と検知されている <br> 0-センサヘッドからの方向がマイナス; 1-センサヘッドからの方向がプラス |

# Input and Output Topics
