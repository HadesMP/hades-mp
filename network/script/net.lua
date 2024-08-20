---@meta Net - The network definitions for HadesMP (Hades II)

---@alias int number
---@alias float number

local Actions = {
    Activate = 0,
    Destroy = 1,
    SwapWeapon = 2,
    ResetWeapon = 3,
    EquipWeapon = 4,
    UnequipWeapon = 5,
    AddWeaponControl = 6,
    SwitchAllegiance = 7,
    PauseGame = 8,
    ResumeGame = 9,
    PlaySound = 10,
    StopSound = 11,
    SetVolume = 12,
    SetPitch = 13,
    SetSoundPosition = 14,
    SetSoundSource = 15,
    PlaySpeech = 16,
    PlaySpeechNow = 17,
    PauseSpeech = 18,
    ResumeSpeech = 19,
    StopSpeech = 20,
    SetAudioListener = 21,
    ClearAudioListener = 22,
    SetAudioEffectState = 23,
    StopAmbientSound = 24,
    PlayAmbientSound = 25,
    FadeOut = 26,
    FadeIn = 27,
    SetSoundCueValue = 28,
    PauseSound = 29,
    ResumeSound = 30,
    KeyOffSoundCue = 31,
    SwapSound = 32,
    SwapAnimation = 33,
    SetMetering = 34,
    CreateMeteringEntry = 35,
    DestroyMeteringEntry = 36,
    AdjustBrightness = 37,
    AdjustFullscreenBloom = 38,
    AdjustRadialBlurStrength = 39,
    AdjustRadialBlurDistance = 40,
    AdjustColorGrading = 41,
    PanCamera = 42,
    FocusCamera = 43,
    AdjustZoom = 44,
    LockCamera = 45,
    UnlockCamera = 46,
    SetCameraZoomWeight = 47,
    SetCameraClamp = 48,
    ClearCameraClamp = 49,
    HaltCamera = 50,
    ShakeScreen = 51,
    ClearUseTarget = 52,
    AddInputBlock = 53,
    RemoveInputBlock = 54,
    TeleportCursor = 55,
    CursorSelectInDirection = 56,
    ToggleMove = 57,
    Rumble = 58,
    SetLightBarColor = 59,
    SetAnimation = 60,
    SetAnimationSpeedMultiplier = 61,
    CreateAnimation = 62,
    CreateAnimations = 63,
    PlayPropertyAnimation = 64,
    StopAnimation = 65,
    SetAnimationFrameTarget = 66,
    BlockVfx = 67,
    UnblockVfx = 68,
    StopLoopingAnimation = 69,
    ColorAnimation = 70,
    StopUnattachedAnimations = 71,
    CreateAnimationsBetween = 72,
    DrawScreenRelative = 73,
    DrawWorldRelative = 74,
    SetGroupVisibility = 75,
    InsertGroupBehind = 76,
    InsertGroupInFront = 77,
    CreateGroup = 78,
    HasGroup = 79,
    Teleport = 80,
    IgnoreGravity = 81,
    ObeyGravity = 82,
    PutDownGently = 83,
    Move = 84,
    Shift = 85,
    Track = 86,
    Stop = 87,
    Halt = 88,
    Attach = 89,
    Unattach = 90,
    UpdateSortScore = 91,
    AddChild = 92,
    AdjustZLocation = 93,
    SetParallax = 94,
    SetInvulnerable = 95,
    SetVulnerable = 96,
    SetRed = 97,
    SetGreen = 98,
    SetBlue = 99,
    SetAlpha = 100,
    SetRGB = 101,
    SetColor = 102,
    SetHSV = 103,
    SetScale = 104,
    SetScaleX = 105,
    SetScaleY = 106,
    MultiplyScale = 107,
    SetAngle = 108,
    SetGoalAngle = 109,
    AngleTowardTarget = 110,
    FlipHorizontal = 111,
    FlipVertical = 112,
    SetTargetable = 113,
    SetUntargetable = 114,
    Flash = 115,
    StopFlashing = 116,
    Shake = 117,
    AddOutline = 118,
    RemoveOutline = 119,
    CreateTextBox = 120,
    ModifyTextBox = 121,
    CreateFormatContainer = 122,
    ModifyFormatContainer = 123,
    ModifySubtitles = 124,
    DestroyTextBox = 125,
    HideTopMenuScreenTooltips = 126,
    FadeObstacleIn = 127,
    HideObstacle = 128,
    AdjustContrast = 129,
    AdjustSaturation = 130,
    FireWeaponFromUnit = 131,
    CreateProjectileFromUnit = 132,
    OverrideWeaponFire = 133,
    ProjectileExists = 134,
    BlockProjectileSpawns = 135,
    ExpireProjectiles = 136,
    DetachProjectiles = 137,
    ArmAndDetonateProjectiles = 138,
    AttachProjectiles = 139,
    SetDamageRadiusMultiplier = 140,
    SetDamageMultiplier = 141,
    RefreshProjectile = 142,
    SetProjectileScale = 143,
    UpdateAttackTarget = 144,
    CancelWeaponFireRequests = 145,
    EndRamWeapons = 146,
    EndBlinkWeapons = 147,
    HasEffect = 148,
    ClearEffect = 149,
    AddEffectBlock = 150,
    RemoveEffectBlock = 151,
    ModifyEffect = 152,
    LoadMap = 153,
    Use = 154,
    UseableOn = 155,
    UseableOff = 156,
    ToggleUseable = 157,
    ApplyForce = 158,
    ApplyUpwardForce = 159,
    ApplyEffectFromWeapon = 160,
    ApplyEffect = 161,
    AddToGroup = 162,
    RemoveFromGroup = 163,
    ClearGroup = 164,
    AttachLua = 165,
    AdjustFrame = 166,
    SwitchActiveUnit = 167,
    GetEffectTimeRemaining = 168,
    GetWeaponEffectiveRange = 169,
    GetUnitDataValue = 170,
    GetThingDataValue = 171,
    GetInteractDataValue = 172,
    GetLifeDataValue = 173,
    GetWeaponDataValue = 174,
    GetProjectileDataValue = 175,
    GetEffectDataValue = 176,
    GetBaseDataValue = 177,
    GetUnitProperty = 178,
    GetWeaponProperty = 179,
    GetProjectileProperty = 180,
    SetThingProperty = 181,
    SetLifeProperty = 182,
    SetObstacleProperty = 183,
    SetInteractProperty = 184,
    SetUnitProperty = 185,
    SetWeaponProperty = 186,
    SetProjectileProperty = 187,
    SetEffectProperty = 188,
    RunThingMethod = 189,
    RunPhysicsMethod = 190,
    RunInteractMethod = 191,
    RunWeaponMethod = 192,
    RunDebugFunction = 193,
    DisableComponent = 194,
    EnableComponent = 195,
    UnlockAchievement = 196,
    SetRichPresence = 197,
    OpenMenu = 198,
    ExitMenu = 199,
    SetMenuOptions = 200,
    AdjustSimulationSpeed = 201,
    AddAutoLockTarget = 202,
    RemoveAutoLockTarget = 203,
    ClearAutoLock = 204,
    ToggleControl = 205,
    CreateCameraWalls = 206,
    DestroyCameraWalls = 207,
    SaveCheckpoint = 208,
    LoadCheckpoint = 209,
    SaveProfile = 211,
    ValidateCheckpoint = 212,
    SetConfigOption = 213,
    LoadPackages = 214,
    UnloadPackages = 215,
    LoadVoiceBank = 216,
    UnloadVoiceBanks = 217,
    PreLoadBinks = 218,
    PerfStartCapture = 223,
    PerfStopCapture = 224,
    IsAlive = 225,
    IsInvulnerable = 226,
    IsUntargetable = 227,
    IsMoving = 228,
    IsImpulsing = 229,
    IsLocationBlocked = 230,
    IsLocationValid = 231,
    IsHorizontallyFlipped = 232,
    IsIdle = 233,
    IsUseable = 234,
    IsInputAllowed = 235,
    IsControlDown = 236,
    IdExists = 237,
    CanAttack = 238,
    CanMove = 239,
    IsCharmed = 240,
    GetCharmDuration = 241,
    NumAlive = 242,
    GetClosest = 243,
    GetFarthest = 244,
    GetClosestInactiveId = 245,
    GetUseTargetId = 246,
    GetDistance = 247,
    IsWithinDistance = 248,
    IsHeadedToward = 249,
    GetScrollOffsetFraction = 250,
    NotifyOnStopped = 251,
    NotifyOnRotationComplete = 252,
    NotifyWithinDistance = 253,
    NotifyWithinDistanceAny = 254,
    NotifyOutsideDistance = 255,
    NotifyOutsideDistanceAll = 256,
    NotifyOnCollide = 257,
    NotifyNotColliding = 258,
    NotifyOnAllDead = 259,
    NotifyOnProjectilesDead = 260,
    NotifyOnPlayerInput = 261,
    NotifyOnInputAllowed = 262,
    NotifyOnControlPressed = 263,
    NotifyOnControlReleased = 264,
    NotifyOnInteract = 265,
    NotifyOnAnimationTimeRemaining = 266,
    NotifyOnFramePassed = 267,
    NotifyOnEffectExpired = 268,
    NotifyOnCanAttack = 269,
    NotifyOnWeaponCharge = 270,
    GetClosestUnitOfType = 271,
    GetIds = 272,
    GetClosestIds = 273,
    GetInProjectilesBlast = 274,
    GetIntersectingIds = 275,
    GetIdsWithSubGroups = 276,
    GetGroupWithSubGroups = 277,
    GetAttachedIds = 278,
    GetIdsByType = 279,
    GetInactiveIds = 280,
    GetInactiveIdsByType = 281,
    GetMapThings = 282,
    GetMapThingsByType = 283,
    GetActiveUnitId = 284,
    GetAttachedToId = 285,
    GetSpawnedById = 286,
    GetConfigOptionValue = 288,
    GetLanguage = 289,
    GetUsername = 290,
    GetTime = 291,
    GetNumConnectedControllers = 292,
    GetName = 293,
    GetGroupName = 294,
    GetAnimationName = 295,
    GetCurrentTargetId = 296,
    GetCursorWorldLocation = 297,
    GetAutoLockId = 298,
    GetBloomSettingName = 299,
    GetAmbientLightColor = 300,
    GetCameraZoom = 301,
    GetLocation = 302,
    GetZLocation = 303,
    GetVelocity = 304,
    GetAngle = 305,
    GetAngleBetween = 306,
    HasLineOfSight = 307,
    SpawnUnit = 308,
    InitUnit = 309,
    SpawnObstacle = 310,
    InitObstacle = 311,
    GetMixingId = 312,
    GetSoundCueValue = 313,
    HasDisplayName = 314,
    GetDisplayName = 315,
    GetWeaponChargeFraction = 316,
    ProfileZoneStart = 318,
    ProfileZoneEnd = 319,
}


---@param Id int
---@param Message any
function _Send(Id, Message) end


---@class Net.Activate

---@param Message Net.Activate
function SendActivate(Message)
    return _Send(Actions.Activate, Message)
end

---@class Net.Destroy

---@param Message Net.Destroy
function SendDestroy(Message)
    return _Send(Actions.Destroy, Message)
end

---@class Net.SwapWeapon

---@param Message Net.SwapWeapon
function SendSwapWeapon(Message)
    return _Send(Actions.SwapWeapon, Message)
end

---@class Net.ResetWeapon

---@param Message Net.ResetWeapon
function SendResetWeapon(Message)
    return _Send(Actions.ResetWeapon, Message)
end

---@class Net.EquipWeapon

---@param Message Net.EquipWeapon
function SendEquipWeapon(Message)
    return _Send(Actions.EquipWeapon, Message)
end

---@class Net.UnequipWeapon

---@param Message Net.UnequipWeapon
function SendUnequipWeapon(Message)
    return _Send(Actions.UnequipWeapon, Message)
end

---@class Net.AddWeaponControl

---@param Message Net.AddWeaponControl
function SendAddWeaponControl(Message)
    return _Send(Actions.AddWeaponControl, Message)
end

---@class Net.SwitchAllegiance

---@param Message Net.SwitchAllegiance
function SendSwitchAllegiance(Message)
    return _Send(Actions.SwitchAllegiance, Message)
end

---@class Net.PauseGame

---@param Message Net.PauseGame
function SendPauseGame(Message)
    return _Send(Actions.PauseGame, Message)
end

---@class Net.ResumeGame

---@param Message Net.ResumeGame
function SendResumeGame(Message)
    return _Send(Actions.ResumeGame, Message)
end

---@class Net.PlaySound

---@param Message Net.PlaySound
function SendPlaySound(Message)
    return _Send(Actions.PlaySound, Message)
end

---@class Net.StopSound

---@param Message Net.StopSound
function SendStopSound(Message)
    return _Send(Actions.StopSound, Message)
end

---@class Net.SetVolume

---@param Message Net.SetVolume
function SendSetVolume(Message)
    return _Send(Actions.SetVolume, Message)
end

---@class Net.SetPitch

---@param Message Net.SetPitch
function SendSetPitch(Message)
    return _Send(Actions.SetPitch, Message)
end

---@class Net.SetSoundPosition

---@param Message Net.SetSoundPosition
function SendSetSoundPosition(Message)
    return _Send(Actions.SetSoundPosition, Message)
end

---@class Net.SetSoundSource

---@param Message Net.SetSoundSource
function SendSetSoundSource(Message)
    return _Send(Actions.SetSoundSource, Message)
end

---@class Net.PlaySpeech

---@param Message Net.PlaySpeech
function SendPlaySpeech(Message)
    return _Send(Actions.PlaySpeech, Message)
end

---@class Net.PlaySpeechNow

---@param Message Net.PlaySpeechNow
function SendPlaySpeechNow(Message)
    return _Send(Actions.PlaySpeechNow, Message)
end

---@class Net.PauseSpeech

---@param Message Net.PauseSpeech
function SendPauseSpeech(Message)
    return _Send(Actions.PauseSpeech, Message)
end

---@class Net.ResumeSpeech

---@param Message Net.ResumeSpeech
function SendResumeSpeech(Message)
    return _Send(Actions.ResumeSpeech, Message)
end

---@class Net.StopSpeech

---@param Message Net.StopSpeech
function SendStopSpeech(Message)
    return _Send(Actions.StopSpeech, Message)
end

---@class Net.SetAudioListener

---@param Message Net.SetAudioListener
function SendSetAudioListener(Message)
    return _Send(Actions.SetAudioListener, Message)
end

---@class Net.ClearAudioListener

---@param Message Net.ClearAudioListener
function SendClearAudioListener(Message)
    return _Send(Actions.ClearAudioListener, Message)
end

---@class Net.SetAudioEffectState

---@param Message Net.SetAudioEffectState
function SendSetAudioEffectState(Message)
    return _Send(Actions.SetAudioEffectState, Message)
end

---@class Net.StopAmbientSound

---@param Message Net.StopAmbientSound
function SendStopAmbientSound(Message)
    return _Send(Actions.StopAmbientSound, Message)
end

---@class Net.PlayAmbientSound

---@param Message Net.PlayAmbientSound
function SendPlayAmbientSound(Message)
    return _Send(Actions.PlayAmbientSound, Message)
end

---@class Net.FadeOut

---@param Message Net.FadeOut
function SendFadeOut(Message)
    return _Send(Actions.FadeOut, Message)
end

---@class Net.FadeIn

---@param Message Net.FadeIn
function SendFadeIn(Message)
    return _Send(Actions.FadeIn, Message)
end

---@class Net.SetSoundCueValue

---@param Message Net.SetSoundCueValue
function SendSetSoundCueValue(Message)
    return _Send(Actions.SetSoundCueValue, Message)
end

---@class Net.PauseSound

---@param Message Net.PauseSound
function SendPauseSound(Message)
    return _Send(Actions.PauseSound, Message)
end

---@class Net.ResumeSound

---@param Message Net.ResumeSound
function SendResumeSound(Message)
    return _Send(Actions.ResumeSound, Message)
end

---@class Net.KeyOffSoundCue

---@param Message Net.KeyOffSoundCue
function SendKeyOffSoundCue(Message)
    return _Send(Actions.KeyOffSoundCue, Message)
end

---@class Net.SwapSound

---@param Message Net.SwapSound
function SendSwapSound(Message)
    return _Send(Actions.SwapSound, Message)
end

---@class Net.SwapAnimation

---@param Message Net.SwapAnimation
function SendSwapAnimation(Message)
    return _Send(Actions.SwapAnimation, Message)
end

---@class Net.SetMetering

---@param Message Net.SetMetering
function SendSetMetering(Message)
    return _Send(Actions.SetMetering, Message)
end

---@class Net.CreateMeteringEntry

---@param Message Net.CreateMeteringEntry
function SendCreateMeteringEntry(Message)
    return _Send(Actions.CreateMeteringEntry, Message)
end

---@class Net.DestroyMeteringEntry

---@param Message Net.DestroyMeteringEntry
function SendDestroyMeteringEntry(Message)
    return _Send(Actions.DestroyMeteringEntry, Message)
end

---@class Net.AdjustBrightness

---@param Message Net.AdjustBrightness
function SendAdjustBrightness(Message)
    return _Send(Actions.AdjustBrightness, Message)
end

---@class Net.AdjustFullscreenBloom

---@param Message Net.AdjustFullscreenBloom
function SendAdjustFullscreenBloom(Message)
    return _Send(Actions.AdjustFullscreenBloom, Message)
end

---@class Net.AdjustRadialBlurStrength

---@param Message Net.AdjustRadialBlurStrength
function SendAdjustRadialBlurStrength(Message)
    return _Send(Actions.AdjustRadialBlurStrength, Message)
end

---@class Net.AdjustRadialBlurDistance

---@param Message Net.AdjustRadialBlurDistance
function SendAdjustRadialBlurDistance(Message)
    return _Send(Actions.AdjustRadialBlurDistance, Message)
end

---@class Net.AdjustColorGrading

---@param Message Net.AdjustColorGrading
function SendAdjustColorGrading(Message)
    return _Send(Actions.AdjustColorGrading, Message)
end

---@class Net.PanCamera

---@param Message Net.PanCamera
function SendPanCamera(Message)
    return _Send(Actions.PanCamera, Message)
end

---@class Net.FocusCamera

---@param Message Net.FocusCamera
function SendFocusCamera(Message)
    return _Send(Actions.FocusCamera, Message)
end

---@class Net.AdjustZoom

---@param Message Net.AdjustZoom
function SendAdjustZoom(Message)
    return _Send(Actions.AdjustZoom, Message)
end

---@class Net.LockCamera

---@param Message Net.LockCamera
function SendLockCamera(Message)
    return _Send(Actions.LockCamera, Message)
end

---@class Net.UnlockCamera

---@param Message Net.UnlockCamera
function SendUnlockCamera(Message)
    return _Send(Actions.UnlockCamera, Message)
end

---@class Net.SetCameraZoomWeight

---@param Message Net.SetCameraZoomWeight
function SendSetCameraZoomWeight(Message)
    return _Send(Actions.SetCameraZoomWeight, Message)
end

---@class Net.SetCameraClamp

---@param Message Net.SetCameraClamp
function SendSetCameraClamp(Message)
    return _Send(Actions.SetCameraClamp, Message)
end

---@class Net.ClearCameraClamp

---@param Message Net.ClearCameraClamp
function SendClearCameraClamp(Message)
    return _Send(Actions.ClearCameraClamp, Message)
end

---@class Net.HaltCamera

---@param Message Net.HaltCamera
function SendHaltCamera(Message)
    return _Send(Actions.HaltCamera, Message)
end

---@class Net.ShakeScreen

---@param Message Net.ShakeScreen
function SendShakeScreen(Message)
    return _Send(Actions.ShakeScreen, Message)
end

---@class Net.ClearUseTarget

---@param Message Net.ClearUseTarget
function SendClearUseTarget(Message)
    return _Send(Actions.ClearUseTarget, Message)
end

---@class Net.AddInputBlock

---@param Message Net.AddInputBlock
function SendAddInputBlock(Message)
    return _Send(Actions.AddInputBlock, Message)
end

---@class Net.RemoveInputBlock

---@param Message Net.RemoveInputBlock
function SendRemoveInputBlock(Message)
    return _Send(Actions.RemoveInputBlock, Message)
end

---@class Net.TeleportCursor

---@param Message Net.TeleportCursor
function SendTeleportCursor(Message)
    return _Send(Actions.TeleportCursor, Message)
end

---@class Net.CursorSelectInDirection

---@param Message Net.CursorSelectInDirection
function SendCursorSelectInDirection(Message)
    return _Send(Actions.CursorSelectInDirection, Message)
end

---@class Net.ToggleMove

---@param Message Net.ToggleMove
function SendToggleMove(Message)
    return _Send(Actions.ToggleMove, Message)
end

---@class Net.Rumble

---@param Message Net.Rumble
function SendRumble(Message)
    return _Send(Actions.Rumble, Message)
end

---@class Net.SetLightBarColor

---@param Message Net.SetLightBarColor
function SendSetLightBarColor(Message)
    return _Send(Actions.SetLightBarColor, Message)
end

---@class Net.SetAnimation

---@param Message Net.SetAnimation
function SendSetAnimation(Message)
    return _Send(Actions.SetAnimation, Message)
end

---@class Net.SetAnimationSpeedMultiplier

---@param Message Net.SetAnimationSpeedMultiplier
function SendSetAnimationSpeedMultiplier(Message)
    return _Send(Actions.SetAnimationSpeedMultiplier, Message)
end

---@class Net.CreateAnimation

---@param Message Net.CreateAnimation
function SendCreateAnimation(Message)
    return _Send(Actions.CreateAnimation, Message)
end

---@class Net.CreateAnimations

---@param Message Net.CreateAnimations
function SendCreateAnimations(Message)
    return _Send(Actions.CreateAnimations, Message)
end

---@class Net.PlayPropertyAnimation

---@param Message Net.PlayPropertyAnimation
function SendPlayPropertyAnimation(Message)
    return _Send(Actions.PlayPropertyAnimation, Message)
end

---@class Net.StopAnimation

---@param Message Net.StopAnimation
function SendStopAnimation(Message)
    return _Send(Actions.StopAnimation, Message)
end

---@class Net.SetAnimationFrameTarget

---@param Message Net.SetAnimationFrameTarget
function SendSetAnimationFrameTarget(Message)
    return _Send(Actions.SetAnimationFrameTarget, Message)
end

---@class Net.BlockVfx

---@param Message Net.BlockVfx
function SendBlockVfx(Message)
    return _Send(Actions.BlockVfx, Message)
end

---@class Net.UnblockVfx

---@param Message Net.UnblockVfx
function SendUnblockVfx(Message)
    return _Send(Actions.UnblockVfx, Message)
end

---@class Net.StopLoopingAnimation

---@param Message Net.StopLoopingAnimation
function SendStopLoopingAnimation(Message)
    return _Send(Actions.StopLoopingAnimation, Message)
end

---@class Net.ColorAnimation

---@param Message Net.ColorAnimation
function SendColorAnimation(Message)
    return _Send(Actions.ColorAnimation, Message)
end

---@class Net.StopUnattachedAnimations

---@param Message Net.StopUnattachedAnimations
function SendStopUnattachedAnimations(Message)
    return _Send(Actions.StopUnattachedAnimations, Message)
end

---@class Net.CreateAnimationsBetween

---@param Message Net.CreateAnimationsBetween
function SendCreateAnimationsBetween(Message)
    return _Send(Actions.CreateAnimationsBetween, Message)
end

---@class Net.DrawScreenRelative

---@param Message Net.DrawScreenRelative
function SendDrawScreenRelative(Message)
    return _Send(Actions.DrawScreenRelative, Message)
end

---@class Net.DrawWorldRelative

---@param Message Net.DrawWorldRelative
function SendDrawWorldRelative(Message)
    return _Send(Actions.DrawWorldRelative, Message)
end

---@class Net.SetGroupVisibility

---@param Message Net.SetGroupVisibility
function SendSetGroupVisibility(Message)
    return _Send(Actions.SetGroupVisibility, Message)
end

---@class Net.InsertGroupBehind

---@param Message Net.InsertGroupBehind
function SendInsertGroupBehind(Message)
    return _Send(Actions.InsertGroupBehind, Message)
end

---@class Net.InsertGroupInFront

---@param Message Net.InsertGroupInFront
function SendInsertGroupInFront(Message)
    return _Send(Actions.InsertGroupInFront, Message)
end

---@class Net.CreateGroup

---@param Message Net.CreateGroup
function SendCreateGroup(Message)
    return _Send(Actions.CreateGroup, Message)
end

---@class Net.HasGroup

---@param Message Net.HasGroup
function SendHasGroup(Message)
    return _Send(Actions.HasGroup, Message)
end

---@class Net.Teleport

---@param Message Net.Teleport
function SendTeleport(Message)
    return _Send(Actions.Teleport, Message)
end

---@class Net.IgnoreGravity

---@param Message Net.IgnoreGravity
function SendIgnoreGravity(Message)
    return _Send(Actions.IgnoreGravity, Message)
end

---@class Net.ObeyGravity

---@param Message Net.ObeyGravity
function SendObeyGravity(Message)
    return _Send(Actions.ObeyGravity, Message)
end

---@class Net.PutDownGently

---@param Message Net.PutDownGently
function SendPutDownGently(Message)
    return _Send(Actions.PutDownGently, Message)
end

---@class Net.Move

---@param Message Net.Move
function SendMove(Message)
    return _Send(Actions.Move, Message)
end

---@class Net.Shift

---@param Message Net.Shift
function SendShift(Message)
    return _Send(Actions.Shift, Message)
end

---@class Net.Track

---@param Message Net.Track
function SendTrack(Message)
    return _Send(Actions.Track, Message)
end

---@class Net.Stop

---@param Message Net.Stop
function SendStop(Message)
    return _Send(Actions.Stop, Message)
end

---@class Net.Halt

---@param Message Net.Halt
function SendHalt(Message)
    return _Send(Actions.Halt, Message)
end

---@class Net.Attach

---@param Message Net.Attach
function SendAttach(Message)
    return _Send(Actions.Attach, Message)
end

---@class Net.Unattach

---@param Message Net.Unattach
function SendUnattach(Message)
    return _Send(Actions.Unattach, Message)
end

---@class Net.UpdateSortScore

---@param Message Net.UpdateSortScore
function SendUpdateSortScore(Message)
    return _Send(Actions.UpdateSortScore, Message)
end

---@class Net.AddChild

---@param Message Net.AddChild
function SendAddChild(Message)
    return _Send(Actions.AddChild, Message)
end

---@class Net.AdjustZLocation

---@param Message Net.AdjustZLocation
function SendAdjustZLocation(Message)
    return _Send(Actions.AdjustZLocation, Message)
end

---@class Net.SetParallax

---@param Message Net.SetParallax
function SendSetParallax(Message)
    return _Send(Actions.SetParallax, Message)
end

---@class Net.SetInvulnerable

---@param Message Net.SetInvulnerable
function SendSetInvulnerable(Message)
    return _Send(Actions.SetInvulnerable, Message)
end

---@class Net.SetVulnerable

---@param Message Net.SetVulnerable
function SendSetVulnerable(Message)
    return _Send(Actions.SetVulnerable, Message)
end

---@class Net.SetRed

---@param Message Net.SetRed
function SendSetRed(Message)
    return _Send(Actions.SetRed, Message)
end

---@class Net.SetGreen

---@param Message Net.SetGreen
function SendSetGreen(Message)
    return _Send(Actions.SetGreen, Message)
end

---@class Net.SetBlue

---@param Message Net.SetBlue
function SendSetBlue(Message)
    return _Send(Actions.SetBlue, Message)
end

---@class Net.SetAlpha

---@param Message Net.SetAlpha
function SendSetAlpha(Message)
    return _Send(Actions.SetAlpha, Message)
end

---@class Net.SetRGB

---@param Message Net.SetRGB
function SendSetRGB(Message)
    return _Send(Actions.SetRGB, Message)
end

---@class Net.SetColor

---@param Message Net.SetColor
function SendSetColor(Message)
    return _Send(Actions.SetColor, Message)
end

---@class Net.SetHSV

---@param Message Net.SetHSV
function SendSetHSV(Message)
    return _Send(Actions.SetHSV, Message)
end

---@class Net.SetScale

---@param Message Net.SetScale
function SendSetScale(Message)
    return _Send(Actions.SetScale, Message)
end

---@class Net.SetScaleX

---@param Message Net.SetScaleX
function SendSetScaleX(Message)
    return _Send(Actions.SetScaleX, Message)
end

---@class Net.SetScaleY

---@param Message Net.SetScaleY
function SendSetScaleY(Message)
    return _Send(Actions.SetScaleY, Message)
end

---@class Net.MultiplyScale

---@param Message Net.MultiplyScale
function SendMultiplyScale(Message)
    return _Send(Actions.MultiplyScale, Message)
end

---@class Net.SetAngle

---@param Message Net.SetAngle
function SendSetAngle(Message)
    return _Send(Actions.SetAngle, Message)
end

---@class Net.SetGoalAngle

---@param Message Net.SetGoalAngle
function SendSetGoalAngle(Message)
    return _Send(Actions.SetGoalAngle, Message)
end

---@class Net.AngleTowardTarget

---@param Message Net.AngleTowardTarget
function SendAngleTowardTarget(Message)
    return _Send(Actions.AngleTowardTarget, Message)
end

---@class Net.FlipHorizontal

---@param Message Net.FlipHorizontal
function SendFlipHorizontal(Message)
    return _Send(Actions.FlipHorizontal, Message)
end

---@class Net.FlipVertical

---@param Message Net.FlipVertical
function SendFlipVertical(Message)
    return _Send(Actions.FlipVertical, Message)
end

---@class Net.SetTargetable

---@param Message Net.SetTargetable
function SendSetTargetable(Message)
    return _Send(Actions.SetTargetable, Message)
end

---@class Net.SetUntargetable

---@param Message Net.SetUntargetable
function SendSetUntargetable(Message)
    return _Send(Actions.SetUntargetable, Message)
end

---@class Net.Flash

---@param Message Net.Flash
function SendFlash(Message)
    return _Send(Actions.Flash, Message)
end

---@class Net.StopFlashing

---@param Message Net.StopFlashing
function SendStopFlashing(Message)
    return _Send(Actions.StopFlashing, Message)
end

---@class Net.Shake

---@param Message Net.Shake
function SendShake(Message)
    return _Send(Actions.Shake, Message)
end

---@class Net.AddOutline

---@param Message Net.AddOutline
function SendAddOutline(Message)
    return _Send(Actions.AddOutline, Message)
end

---@class Net.RemoveOutline

---@param Message Net.RemoveOutline
function SendRemoveOutline(Message)
    return _Send(Actions.RemoveOutline, Message)
end

---@class Net.CreateTextBox

---@param Message Net.CreateTextBox
function SendCreateTextBox(Message)
    return _Send(Actions.CreateTextBox, Message)
end

---@class Net.ModifyTextBox

---@param Message Net.ModifyTextBox
function SendModifyTextBox(Message)
    return _Send(Actions.ModifyTextBox, Message)
end

---@class Net.CreateFormatContainer

---@param Message Net.CreateFormatContainer
function SendCreateFormatContainer(Message)
    return _Send(Actions.CreateFormatContainer, Message)
end

---@class Net.ModifyFormatContainer

---@param Message Net.ModifyFormatContainer
function SendModifyFormatContainer(Message)
    return _Send(Actions.ModifyFormatContainer, Message)
end

---@class Net.ModifySubtitles

---@param Message Net.ModifySubtitles
function SendModifySubtitles(Message)
    return _Send(Actions.ModifySubtitles, Message)
end

---@class Net.DestroyTextBox

---@param Message Net.DestroyTextBox
function SendDestroyTextBox(Message)
    return _Send(Actions.DestroyTextBox, Message)
end

---@class Net.HideTopMenuScreenTooltips

---@param Message Net.HideTopMenuScreenTooltips
function SendHideTopMenuScreenTooltips(Message)
    return _Send(Actions.HideTopMenuScreenTooltips, Message)
end

---@class Net.FadeObstacleIn

---@param Message Net.FadeObstacleIn
function SendFadeObstacleIn(Message)
    return _Send(Actions.FadeObstacleIn, Message)
end

---@class Net.HideObstacle

---@param Message Net.HideObstacle
function SendHideObstacle(Message)
    return _Send(Actions.HideObstacle, Message)
end

---@class Net.AdjustContrast

---@param Message Net.AdjustContrast
function SendAdjustContrast(Message)
    return _Send(Actions.AdjustContrast, Message)
end

---@class Net.AdjustSaturation

---@param Message Net.AdjustSaturation
function SendAdjustSaturation(Message)
    return _Send(Actions.AdjustSaturation, Message)
end

---@class Net.FireWeaponFromUnit

---@param Message Net.FireWeaponFromUnit
function SendFireWeaponFromUnit(Message)
    return _Send(Actions.FireWeaponFromUnit, Message)
end

---@class Net.CreateProjectileFromUnit

---@param Message Net.CreateProjectileFromUnit
function SendCreateProjectileFromUnit(Message)
    return _Send(Actions.CreateProjectileFromUnit, Message)
end

---@class Net.OverrideWeaponFire

---@param Message Net.OverrideWeaponFire
function SendOverrideWeaponFire(Message)
    return _Send(Actions.OverrideWeaponFire, Message)
end

---@class Net.ProjectileExists

---@param Message Net.ProjectileExists
function SendProjectileExists(Message)
    return _Send(Actions.ProjectileExists, Message)
end

---@class Net.BlockProjectileSpawns

---@param Message Net.BlockProjectileSpawns
function SendBlockProjectileSpawns(Message)
    return _Send(Actions.BlockProjectileSpawns, Message)
end

---@class Net.ExpireProjectiles

---@param Message Net.ExpireProjectiles
function SendExpireProjectiles(Message)
    return _Send(Actions.ExpireProjectiles, Message)
end

---@class Net.DetachProjectiles

---@param Message Net.DetachProjectiles
function SendDetachProjectiles(Message)
    return _Send(Actions.DetachProjectiles, Message)
end

---@class Net.ArmAndDetonateProjectiles

---@param Message Net.ArmAndDetonateProjectiles
function SendArmAndDetonateProjectiles(Message)
    return _Send(Actions.ArmAndDetonateProjectiles, Message)
end

---@class Net.AttachProjectiles

---@param Message Net.AttachProjectiles
function SendAttachProjectiles(Message)
    return _Send(Actions.AttachProjectiles, Message)
end

---@class Net.SetDamageRadiusMultiplier

---@param Message Net.SetDamageRadiusMultiplier
function SendSetDamageRadiusMultiplier(Message)
    return _Send(Actions.SetDamageRadiusMultiplier, Message)
end

---@class Net.SetDamageMultiplier

---@param Message Net.SetDamageMultiplier
function SendSetDamageMultiplier(Message)
    return _Send(Actions.SetDamageMultiplier, Message)
end

---@class Net.RefreshProjectile

---@param Message Net.RefreshProjectile
function SendRefreshProjectile(Message)
    return _Send(Actions.RefreshProjectile, Message)
end

---@class Net.SetProjectileScale

---@param Message Net.SetProjectileScale
function SendSetProjectileScale(Message)
    return _Send(Actions.SetProjectileScale, Message)
end

---@class Net.UpdateAttackTarget

---@param Message Net.UpdateAttackTarget
function SendUpdateAttackTarget(Message)
    return _Send(Actions.UpdateAttackTarget, Message)
end

---@class Net.CancelWeaponFireRequests

---@param Message Net.CancelWeaponFireRequests
function SendCancelWeaponFireRequests(Message)
    return _Send(Actions.CancelWeaponFireRequests, Message)
end

---@class Net.EndRamWeapons

---@param Message Net.EndRamWeapons
function SendEndRamWeapons(Message)
    return _Send(Actions.EndRamWeapons, Message)
end

---@class Net.EndBlinkWeapons

---@param Message Net.EndBlinkWeapons
function SendEndBlinkWeapons(Message)
    return _Send(Actions.EndBlinkWeapons, Message)
end

---@class Net.HasEffect

---@param Message Net.HasEffect
function SendHasEffect(Message)
    return _Send(Actions.HasEffect, Message)
end

---@class Net.ClearEffect

---@param Message Net.ClearEffect
function SendClearEffect(Message)
    return _Send(Actions.ClearEffect, Message)
end

---@class Net.AddEffectBlock

---@param Message Net.AddEffectBlock
function SendAddEffectBlock(Message)
    return _Send(Actions.AddEffectBlock, Message)
end

---@class Net.RemoveEffectBlock

---@param Message Net.RemoveEffectBlock
function SendRemoveEffectBlock(Message)
    return _Send(Actions.RemoveEffectBlock, Message)
end

---@class Net.ModifyEffect

---@param Message Net.ModifyEffect
function SendModifyEffect(Message)
    return _Send(Actions.ModifyEffect, Message)
end

---@class Net.LoadMap

---@param Message Net.LoadMap
function SendLoadMap(Message)
    return _Send(Actions.LoadMap, Message)
end

---@class Net.Use

---@param Message Net.Use
function SendUse(Message)
    return _Send(Actions.Use, Message)
end

---@class Net.UseableOn

---@param Message Net.UseableOn
function SendUseableOn(Message)
    return _Send(Actions.UseableOn, Message)
end

---@class Net.UseableOff

---@param Message Net.UseableOff
function SendUseableOff(Message)
    return _Send(Actions.UseableOff, Message)
end

---@class Net.ToggleUseable

---@param Message Net.ToggleUseable
function SendToggleUseable(Message)
    return _Send(Actions.ToggleUseable, Message)
end

---@class Net.ApplyForce

---@param Message Net.ApplyForce
function SendApplyForce(Message)
    return _Send(Actions.ApplyForce, Message)
end

---@class Net.ApplyUpwardForce

---@param Message Net.ApplyUpwardForce
function SendApplyUpwardForce(Message)
    return _Send(Actions.ApplyUpwardForce, Message)
end

---@class Net.ApplyEffectFromWeapon

---@param Message Net.ApplyEffectFromWeapon
function SendApplyEffectFromWeapon(Message)
    return _Send(Actions.ApplyEffectFromWeapon, Message)
end

---@class Net.ApplyEffect

---@param Message Net.ApplyEffect
function SendApplyEffect(Message)
    return _Send(Actions.ApplyEffect, Message)
end

---@class Net.AddToGroup

---@param Message Net.AddToGroup
function SendAddToGroup(Message)
    return _Send(Actions.AddToGroup, Message)
end

---@class Net.RemoveFromGroup

---@param Message Net.RemoveFromGroup
function SendRemoveFromGroup(Message)
    return _Send(Actions.RemoveFromGroup, Message)
end

---@class Net.ClearGroup

---@param Message Net.ClearGroup
function SendClearGroup(Message)
    return _Send(Actions.ClearGroup, Message)
end

---@class Net.AttachLua

---@param Message Net.AttachLua
function SendAttachLua(Message)
    return _Send(Actions.AttachLua, Message)
end

---@class Net.AdjustFrame

---@param Message Net.AdjustFrame
function SendAdjustFrame(Message)
    return _Send(Actions.AdjustFrame, Message)
end

---@class Net.SwitchActiveUnit

---@param Message Net.SwitchActiveUnit
function SendSwitchActiveUnit(Message)
    return _Send(Actions.SwitchActiveUnit, Message)
end

---@class Net.GetEffectTimeRemaining

---@param Message Net.GetEffectTimeRemaining
function SendGetEffectTimeRemaining(Message)
    return _Send(Actions.GetEffectTimeRemaining, Message)
end

---@class Net.GetWeaponEffectiveRange

---@param Message Net.GetWeaponEffectiveRange
function SendGetWeaponEffectiveRange(Message)
    return _Send(Actions.GetWeaponEffectiveRange, Message)
end

---@class Net.GetUnitDataValue

---@param Message Net.GetUnitDataValue
function SendGetUnitDataValue(Message)
    return _Send(Actions.GetUnitDataValue, Message)
end

---@class Net.GetThingDataValue

---@param Message Net.GetThingDataValue
function SendGetThingDataValue(Message)
    return _Send(Actions.GetThingDataValue, Message)
end

---@class Net.GetInteractDataValue

---@param Message Net.GetInteractDataValue
function SendGetInteractDataValue(Message)
    return _Send(Actions.GetInteractDataValue, Message)
end

---@class Net.GetLifeDataValue

---@param Message Net.GetLifeDataValue
function SendGetLifeDataValue(Message)
    return _Send(Actions.GetLifeDataValue, Message)
end

---@class Net.GetWeaponDataValue

---@param Message Net.GetWeaponDataValue
function SendGetWeaponDataValue(Message)
    return _Send(Actions.GetWeaponDataValue, Message)
end

---@class Net.GetProjectileDataValue

---@param Message Net.GetProjectileDataValue
function SendGetProjectileDataValue(Message)
    return _Send(Actions.GetProjectileDataValue, Message)
end

---@class Net.GetEffectDataValue

---@param Message Net.GetEffectDataValue
function SendGetEffectDataValue(Message)
    return _Send(Actions.GetEffectDataValue, Message)
end

---@class Net.GetBaseDataValue

---@param Message Net.GetBaseDataValue
function SendGetBaseDataValue(Message)
    return _Send(Actions.GetBaseDataValue, Message)
end

---@class Net.GetUnitProperty

---@param Message Net.GetUnitProperty
function SendGetUnitProperty(Message)
    return _Send(Actions.GetUnitProperty, Message)
end

---@class Net.GetWeaponProperty

---@param Message Net.GetWeaponProperty
function SendGetWeaponProperty(Message)
    return _Send(Actions.GetWeaponProperty, Message)
end

---@class Net.GetProjectileProperty

---@param Message Net.GetProjectileProperty
function SendGetProjectileProperty(Message)
    return _Send(Actions.GetProjectileProperty, Message)
end

---@class Net.SetThingProperty

---@param Message Net.SetThingProperty
function SendSetThingProperty(Message)
    return _Send(Actions.SetThingProperty, Message)
end

---@class Net.SetLifeProperty

---@param Message Net.SetLifeProperty
function SendSetLifeProperty(Message)
    return _Send(Actions.SetLifeProperty, Message)
end

---@class Net.SetObstacleProperty

---@param Message Net.SetObstacleProperty
function SendSetObstacleProperty(Message)
    return _Send(Actions.SetObstacleProperty, Message)
end

---@class Net.SetInteractProperty

---@param Message Net.SetInteractProperty
function SendSetInteractProperty(Message)
    return _Send(Actions.SetInteractProperty, Message)
end

---@class Net.SetUnitProperty

---@param Message Net.SetUnitProperty
function SendSetUnitProperty(Message)
    return _Send(Actions.SetUnitProperty, Message)
end

---@class Net.SetWeaponProperty

---@param Message Net.SetWeaponProperty
function SendSetWeaponProperty(Message)
    return _Send(Actions.SetWeaponProperty, Message)
end

---@class Net.SetProjectileProperty

---@param Message Net.SetProjectileProperty
function SendSetProjectileProperty(Message)
    return _Send(Actions.SetProjectileProperty, Message)
end

---@class Net.SetEffectProperty

---@param Message Net.SetEffectProperty
function SendSetEffectProperty(Message)
    return _Send(Actions.SetEffectProperty, Message)
end

---@class Net.RunThingMethod

---@param Message Net.RunThingMethod
function SendRunThingMethod(Message)
    return _Send(Actions.RunThingMethod, Message)
end

---@class Net.RunPhysicsMethod

---@param Message Net.RunPhysicsMethod
function SendRunPhysicsMethod(Message)
    return _Send(Actions.RunPhysicsMethod, Message)
end

---@class Net.RunInteractMethod

---@param Message Net.RunInteractMethod
function SendRunInteractMethod(Message)
    return _Send(Actions.RunInteractMethod, Message)
end

---@class Net.RunWeaponMethod

---@param Message Net.RunWeaponMethod
function SendRunWeaponMethod(Message)
    return _Send(Actions.RunWeaponMethod, Message)
end

---@class Net.RunDebugFunction

---@param Message Net.RunDebugFunction
function SendRunDebugFunction(Message)
    return _Send(Actions.RunDebugFunction, Message)
end

---@class Net.DisableComponent

---@param Message Net.DisableComponent
function SendDisableComponent(Message)
    return _Send(Actions.DisableComponent, Message)
end

---@class Net.EnableComponent

---@param Message Net.EnableComponent
function SendEnableComponent(Message)
    return _Send(Actions.EnableComponent, Message)
end

---@class Net.UnlockAchievement

---@param Message Net.UnlockAchievement
function SendUnlockAchievement(Message)
    return _Send(Actions.UnlockAchievement, Message)
end

---@class Net.SetRichPresence

---@param Message Net.SetRichPresence
function SendSetRichPresence(Message)
    return _Send(Actions.SetRichPresence, Message)
end

---@class Net.OpenMenu

---@param Message Net.OpenMenu
function SendOpenMenu(Message)
    return _Send(Actions.OpenMenu, Message)
end

---@class Net.ExitMenu

---@param Message Net.ExitMenu
function SendExitMenu(Message)
    return _Send(Actions.ExitMenu, Message)
end

---@class Net.SetMenuOptions

---@param Message Net.SetMenuOptions
function SendSetMenuOptions(Message)
    return _Send(Actions.SetMenuOptions, Message)
end

---@class Net.AdjustSimulationSpeed

---@param Message Net.AdjustSimulationSpeed
function SendAdjustSimulationSpeed(Message)
    return _Send(Actions.AdjustSimulationSpeed, Message)
end

---@class Net.AddAutoLockTarget

---@param Message Net.AddAutoLockTarget
function SendAddAutoLockTarget(Message)
    return _Send(Actions.AddAutoLockTarget, Message)
end

---@class Net.RemoveAutoLockTarget

---@param Message Net.RemoveAutoLockTarget
function SendRemoveAutoLockTarget(Message)
    return _Send(Actions.RemoveAutoLockTarget, Message)
end

---@class Net.ClearAutoLock

---@param Message Net.ClearAutoLock
function SendClearAutoLock(Message)
    return _Send(Actions.ClearAutoLock, Message)
end

---@class Net.ToggleControl

---@param Message Net.ToggleControl
function SendToggleControl(Message)
    return _Send(Actions.ToggleControl, Message)
end

---@class Net.CreateCameraWalls

---@param Message Net.CreateCameraWalls
function SendCreateCameraWalls(Message)
    return _Send(Actions.CreateCameraWalls, Message)
end

---@class Net.DestroyCameraWalls

---@param Message Net.DestroyCameraWalls
function SendDestroyCameraWalls(Message)
    return _Send(Actions.DestroyCameraWalls, Message)
end

---@class Net.SaveCheckpoint

---@param Message Net.SaveCheckpoint
function SendSaveCheckpoint(Message)
    return _Send(Actions.SaveCheckpoint, Message)
end

---@class Net.LoadCheckpoint

---@param Message Net.LoadCheckpoint
function SendLoadCheckpoint(Message)
    return _Send(Actions.LoadCheckpoint, Message)
end

---@class Net.HasSaveFile

---@param Message Net.HasSaveFile
function SendHasSaveFile(Message)
    return _Send(Actions.HasSaveFile, Message)
end

---@class Net.SaveProfile

---@param Message Net.SaveProfile
function SendSaveProfile(Message)
    return _Send(Actions.SaveProfile, Message)
end

---@class Net.ValidateCheckpoint

---@param Message Net.ValidateCheckpoint
function SendValidateCheckpoint(Message)
    return _Send(Actions.ValidateCheckpoint, Message)
end

---@class Net.SetConfigOption

---@param Message Net.SetConfigOption
function SendSetConfigOption(Message)
    return _Send(Actions.SetConfigOption, Message)
end

---@class Net.LoadPackages

---@param Message Net.LoadPackages
function SendLoadPackages(Message)
    return _Send(Actions.LoadPackages, Message)
end

---@class Net.UnloadPackages

---@param Message Net.UnloadPackages
function SendUnloadPackages(Message)
    return _Send(Actions.UnloadPackages, Message)
end

---@class Net.LoadVoiceBank

---@param Message Net.LoadVoiceBank
function SendLoadVoiceBank(Message)
    return _Send(Actions.LoadVoiceBank, Message)
end

---@class Net.UnloadVoiceBanks

---@param Message Net.UnloadVoiceBanks
function SendUnloadVoiceBanks(Message)
    return _Send(Actions.UnloadVoiceBanks, Message)
end

---@class Net.PreLoadBinks

---@param Message Net.PreLoadBinks
function SendPreLoadBinks(Message)
    return _Send(Actions.PreLoadBinks, Message)
end

---@class Net.DebugMessage

---@param Message Net.DebugMessage
function SendDebugMessage(Message)
    return _Send(Actions.DebugMessage, Message)
end

---@class Net.DebugPrint

---@param Message Net.DebugPrint
function SendDebugPrint(Message)
    return _Send(Actions.DebugPrint, Message)
end

---@class Net.DebugAssert

---@param Message Net.DebugAssert
function SendDebugAssert(Message)
    return _Send(Actions.DebugAssert, Message)
end

---@class Net.DebugException

---@param Message Net.DebugException
function SendDebugException(Message)
    return _Send(Actions.DebugException, Message)
end

---@class Net.PerfStartCapture

---@param Message Net.PerfStartCapture
function SendPerfStartCapture(Message)
    return _Send(Actions.PerfStartCapture, Message)
end

---@class Net.PerfStopCapture

---@param Message Net.PerfStopCapture
function SendPerfStopCapture(Message)
    return _Send(Actions.PerfStopCapture, Message)
end

---@class Net.IsAlive

---@param Message Net.IsAlive
function SendIsAlive(Message)
    return _Send(Actions.IsAlive, Message)
end

---@class Net.IsInvulnerable

---@param Message Net.IsInvulnerable
function SendIsInvulnerable(Message)
    return _Send(Actions.IsInvulnerable, Message)
end

---@class Net.IsUntargetable

---@param Message Net.IsUntargetable
function SendIsUntargetable(Message)
    return _Send(Actions.IsUntargetable, Message)
end

---@class Net.IsMoving

---@param Message Net.IsMoving
function SendIsMoving(Message)
    return _Send(Actions.IsMoving, Message)
end

---@class Net.IsImpulsing

---@param Message Net.IsImpulsing
function SendIsImpulsing(Message)
    return _Send(Actions.IsImpulsing, Message)
end

---@class Net.IsLocationBlocked

---@param Message Net.IsLocationBlocked
function SendIsLocationBlocked(Message)
    return _Send(Actions.IsLocationBlocked, Message)
end

---@class Net.IsLocationValid

---@param Message Net.IsLocationValid
function SendIsLocationValid(Message)
    return _Send(Actions.IsLocationValid, Message)
end

---@class Net.IsHorizontallyFlipped

---@param Message Net.IsHorizontallyFlipped
function SendIsHorizontallyFlipped(Message)
    return _Send(Actions.IsHorizontallyFlipped, Message)
end

---@class Net.IsIdle

---@param Message Net.IsIdle
function SendIsIdle(Message)
    return _Send(Actions.IsIdle, Message)
end

---@class Net.IsUseable

---@param Message Net.IsUseable
function SendIsUseable(Message)
    return _Send(Actions.IsUseable, Message)
end

---@class Net.IsInputAllowed

---@param Message Net.IsInputAllowed
function SendIsInputAllowed(Message)
    return _Send(Actions.IsInputAllowed, Message)
end

---@class Net.IsControlDown

---@param Message Net.IsControlDown
function SendIsControlDown(Message)
    return _Send(Actions.IsControlDown, Message)
end

---@class Net.IdExists

---@param Message Net.IdExists
function SendIdExists(Message)
    return _Send(Actions.IdExists, Message)
end

---@class Net.CanAttack

---@param Message Net.CanAttack
function SendCanAttack(Message)
    return _Send(Actions.CanAttack, Message)
end

---@class Net.CanMove

---@param Message Net.CanMove
function SendCanMove(Message)
    return _Send(Actions.CanMove, Message)
end

---@class Net.IsCharmed

---@param Message Net.IsCharmed
function SendIsCharmed(Message)
    return _Send(Actions.IsCharmed, Message)
end

---@class Net.GetCharmDuration

---@param Message Net.GetCharmDuration
function SendGetCharmDuration(Message)
    return _Send(Actions.GetCharmDuration, Message)
end

---@class Net.NumAlive

---@param Message Net.NumAlive
function SendNumAlive(Message)
    return _Send(Actions.NumAlive, Message)
end

---@class Net.GetClosest

---@param Message Net.GetClosest
function SendGetClosest(Message)
    return _Send(Actions.GetClosest, Message)
end

---@class Net.GetFarthest

---@param Message Net.GetFarthest
function SendGetFarthest(Message)
    return _Send(Actions.GetFarthest, Message)
end

---@class Net.GetClosestInactiveId

---@param Message Net.GetClosestInactiveId
function SendGetClosestInactiveId(Message)
    return _Send(Actions.GetClosestInactiveId, Message)
end

---@class Net.GetUseTargetId

---@param Message Net.GetUseTargetId
function SendGetUseTargetId(Message)
    return _Send(Actions.GetUseTargetId, Message)
end

---@class Net.GetDistance

---@param Message Net.GetDistance
function SendGetDistance(Message)
    return _Send(Actions.GetDistance, Message)
end

---@class Net.IsWithinDistance

---@param Message Net.IsWithinDistance
function SendIsWithinDistance(Message)
    return _Send(Actions.IsWithinDistance, Message)
end

---@class Net.IsHeadedToward

---@param Message Net.IsHeadedToward
function SendIsHeadedToward(Message)
    return _Send(Actions.IsHeadedToward, Message)
end

---@class Net.GetScrollOffsetFraction

---@param Message Net.GetScrollOffsetFraction
function SendGetScrollOffsetFraction(Message)
    return _Send(Actions.GetScrollOffsetFraction, Message)
end

---@class Net.NotifyOnStopped

---@param Message Net.NotifyOnStopped
function SendNotifyOnStopped(Message)
    return _Send(Actions.NotifyOnStopped, Message)
end

---@class Net.NotifyOnRotationComplete

---@param Message Net.NotifyOnRotationComplete
function SendNotifyOnRotationComplete(Message)
    return _Send(Actions.NotifyOnRotationComplete, Message)
end

---@class Net.NotifyWithinDistance

---@param Message Net.NotifyWithinDistance
function SendNotifyWithinDistance(Message)
    return _Send(Actions.NotifyWithinDistance, Message)
end

---@class Net.NotifyWithinDistanceAny

---@param Message Net.NotifyWithinDistanceAny
function SendNotifyWithinDistanceAny(Message)
    return _Send(Actions.NotifyWithinDistanceAny, Message)
end

---@class Net.NotifyOutsideDistance

---@param Message Net.NotifyOutsideDistance
function SendNotifyOutsideDistance(Message)
    return _Send(Actions.NotifyOutsideDistance, Message)
end

---@class Net.NotifyOutsideDistanceAll

---@param Message Net.NotifyOutsideDistanceAll
function SendNotifyOutsideDistanceAll(Message)
    return _Send(Actions.NotifyOutsideDistanceAll, Message)
end

---@class Net.NotifyOnCollide

---@param Message Net.NotifyOnCollide
function SendNotifyOnCollide(Message)
    return _Send(Actions.NotifyOnCollide, Message)
end

---@class Net.NotifyNotColliding

---@param Message Net.NotifyNotColliding
function SendNotifyNotColliding(Message)
    return _Send(Actions.NotifyNotColliding, Message)
end

---@class Net.NotifyOnAllDead

---@param Message Net.NotifyOnAllDead
function SendNotifyOnAllDead(Message)
    return _Send(Actions.NotifyOnAllDead, Message)
end

---@class Net.NotifyOnProjectilesDead

---@param Message Net.NotifyOnProjectilesDead
function SendNotifyOnProjectilesDead(Message)
    return _Send(Actions.NotifyOnProjectilesDead, Message)
end

---@class Net.NotifyOnPlayerInput

---@param Message Net.NotifyOnPlayerInput
function SendNotifyOnPlayerInput(Message)
    return _Send(Actions.NotifyOnPlayerInput, Message)
end

---@class Net.NotifyOnInputAllowed

---@param Message Net.NotifyOnInputAllowed
function SendNotifyOnInputAllowed(Message)
    return _Send(Actions.NotifyOnInputAllowed, Message)
end

---@class Net.NotifyOnControlPressed

---@param Message Net.NotifyOnControlPressed
function SendNotifyOnControlPressed(Message)
    return _Send(Actions.NotifyOnControlPressed, Message)
end

---@class Net.NotifyOnControlReleased

---@param Message Net.NotifyOnControlReleased
function SendNotifyOnControlReleased(Message)
    return _Send(Actions.NotifyOnControlReleased, Message)
end

---@class Net.NotifyOnInteract

---@param Message Net.NotifyOnInteract
function SendNotifyOnInteract(Message)
    return _Send(Actions.NotifyOnInteract, Message)
end

---@class Net.NotifyOnAnimationTimeRemaining

---@param Message Net.NotifyOnAnimationTimeRemaining
function SendNotifyOnAnimationTimeRemaining(Message)
    return _Send(Actions.NotifyOnAnimationTimeRemaining, Message)
end

---@class Net.NotifyOnFramePassed

---@param Message Net.NotifyOnFramePassed
function SendNotifyOnFramePassed(Message)
    return _Send(Actions.NotifyOnFramePassed, Message)
end

---@class Net.NotifyOnEffectExpired

---@param Message Net.NotifyOnEffectExpired
function SendNotifyOnEffectExpired(Message)
    return _Send(Actions.NotifyOnEffectExpired, Message)
end

---@class Net.NotifyOnCanAttack

---@param Message Net.NotifyOnCanAttack
function SendNotifyOnCanAttack(Message)
    return _Send(Actions.NotifyOnCanAttack, Message)
end

---@class Net.NotifyOnWeaponCharge

---@param Message Net.NotifyOnWeaponCharge
function SendNotifyOnWeaponCharge(Message)
    return _Send(Actions.NotifyOnWeaponCharge, Message)
end

---@class Net.GetClosestUnitOfType

---@param Message Net.GetClosestUnitOfType
function SendGetClosestUnitOfType(Message)
    return _Send(Actions.GetClosestUnitOfType, Message)
end

---@class Net.GetIds

---@param Message Net.GetIds
function SendGetIds(Message)
    return _Send(Actions.GetIds, Message)
end

---@class Net.GetClosestIds

---@param Message Net.GetClosestIds
function SendGetClosestIds(Message)
    return _Send(Actions.GetClosestIds, Message)
end

---@class Net.GetInProjectilesBlast

---@param Message Net.GetInProjectilesBlast
function SendGetInProjectilesBlast(Message)
    return _Send(Actions.GetInProjectilesBlast, Message)
end

---@class Net.GetIntersectingIds

---@param Message Net.GetIntersectingIds
function SendGetIntersectingIds(Message)
    return _Send(Actions.GetIntersectingIds, Message)
end

---@class Net.GetIdsWithSubGroups

---@param Message Net.GetIdsWithSubGroups
function SendGetIdsWithSubGroups(Message)
    return _Send(Actions.GetIdsWithSubGroups, Message)
end

---@class Net.GetGroupWithSubGroups

---@param Message Net.GetGroupWithSubGroups
function SendGetGroupWithSubGroups(Message)
    return _Send(Actions.GetGroupWithSubGroups, Message)
end

---@class Net.GetAttachedIds

---@param Message Net.GetAttachedIds
function SendGetAttachedIds(Message)
    return _Send(Actions.GetAttachedIds, Message)
end

---@class Net.GetIdsByType

---@param Message Net.GetIdsByType
function SendGetIdsByType(Message)
    return _Send(Actions.GetIdsByType, Message)
end

---@class Net.GetInactiveIds

---@param Message Net.GetInactiveIds
function SendGetInactiveIds(Message)
    return _Send(Actions.GetInactiveIds, Message)
end

---@class Net.GetInactiveIdsByType

---@param Message Net.GetInactiveIdsByType
function SendGetInactiveIdsByType(Message)
    return _Send(Actions.GetInactiveIdsByType, Message)
end

---@class Net.GetMapThings

---@param Message Net.GetMapThings
function SendGetMapThings(Message)
    return _Send(Actions.GetMapThings, Message)
end

---@class Net.GetMapThingsByType

---@param Message Net.GetMapThingsByType
function SendGetMapThingsByType(Message)
    return _Send(Actions.GetMapThingsByType, Message)
end

---@class Net.GetActiveUnitId

---@param Message Net.GetActiveUnitId
function SendGetActiveUnitId(Message)
    return _Send(Actions.GetActiveUnitId, Message)
end

---@class Net.GetAttachedToId

---@param Message Net.GetAttachedToId
function SendGetAttachedToId(Message)
    return _Send(Actions.GetAttachedToId, Message)
end

---@class Net.GetSpawnedById

---@param Message Net.GetSpawnedById
function SendGetSpawnedById(Message)
    return _Send(Actions.GetSpawnedById, Message)
end

---@class Net.IsPS4

---@param Message Net.IsPS4
function SendIsPS4(Message)
    return _Send(Actions.IsPS4, Message)
end

---@class Net.GetConfigOptionValue

---@param Message Net.GetConfigOptionValue
function SendGetConfigOptionValue(Message)
    return _Send(Actions.GetConfigOptionValue, Message)
end

---@class Net.GetLanguage

---@param Message Net.GetLanguage
function SendGetLanguage(Message)
    return _Send(Actions.GetLanguage, Message)
end

---@class Net.GetUsername

---@param Message Net.GetUsername
function SendGetUsername(Message)
    return _Send(Actions.GetUsername, Message)
end

---@class Net.GetTime

---@param Message Net.GetTime
function SendGetTime(Message)
    return _Send(Actions.GetTime, Message)
end

---@class Net.GetNumConnectedControllers

---@param Message Net.GetNumConnectedControllers
function SendGetNumConnectedControllers(Message)
    return _Send(Actions.GetNumConnectedControllers, Message)
end

---@class Net.GetName

---@param Message Net.GetName
function SendGetName(Message)
    return _Send(Actions.GetName, Message)
end

---@class Net.GetGroupName

---@param Message Net.GetGroupName
function SendGetGroupName(Message)
    return _Send(Actions.GetGroupName, Message)
end

---@class Net.GetAnimationName

---@param Message Net.GetAnimationName
function SendGetAnimationName(Message)
    return _Send(Actions.GetAnimationName, Message)
end

---@class Net.GetCurrentTargetId

---@param Message Net.GetCurrentTargetId
function SendGetCurrentTargetId(Message)
    return _Send(Actions.GetCurrentTargetId, Message)
end

---@class Net.GetCursorWorldLocation

---@param Message Net.GetCursorWorldLocation
function SendGetCursorWorldLocation(Message)
    return _Send(Actions.GetCursorWorldLocation, Message)
end

---@class Net.GetAutoLockId

---@param Message Net.GetAutoLockId
function SendGetAutoLockId(Message)
    return _Send(Actions.GetAutoLockId, Message)
end

---@class Net.GetBloomSettingName

---@param Message Net.GetBloomSettingName
function SendGetBloomSettingName(Message)
    return _Send(Actions.GetBloomSettingName, Message)
end

---@class Net.GetAmbientLightColor

---@param Message Net.GetAmbientLightColor
function SendGetAmbientLightColor(Message)
    return _Send(Actions.GetAmbientLightColor, Message)
end

---@class Net.GetCameraZoom

---@param Message Net.GetCameraZoom
function SendGetCameraZoom(Message)
    return _Send(Actions.GetCameraZoom, Message)
end

---@class Net.GetLocation

---@param Message Net.GetLocation
function SendGetLocation(Message)
    return _Send(Actions.GetLocation, Message)
end

---@class Net.GetZLocation

---@param Message Net.GetZLocation
function SendGetZLocation(Message)
    return _Send(Actions.GetZLocation, Message)
end

---@class Net.GetVelocity

---@param Message Net.GetVelocity
function SendGetVelocity(Message)
    return _Send(Actions.GetVelocity, Message)
end

---@class Net.GetAngle

---@param Message Net.GetAngle
function SendGetAngle(Message)
    return _Send(Actions.GetAngle, Message)
end

---@class Net.GetAngleBetween

---@param Message Net.GetAngleBetween
function SendGetAngleBetween(Message)
    return _Send(Actions.GetAngleBetween, Message)
end

---@class Net.HasLineOfSight

---@param Message Net.HasLineOfSight
function SendHasLineOfSight(Message)
    return _Send(Actions.HasLineOfSight, Message)
end

---@class Net.SpawnUnit

---@param Message Net.SpawnUnit
function SendSpawnUnit(Message)
    return _Send(Actions.SpawnUnit, Message)
end

---@class Net.InitUnit

---@param Message Net.InitUnit
function SendInitUnit(Message)
    return _Send(Actions.InitUnit, Message)
end

---@class Net.SpawnObstacle

---@param Message Net.SpawnObstacle
function SendSpawnObstacle(Message)
    return _Send(Actions.SpawnObstacle, Message)
end

---@class Net.InitObstacle

---@param Message Net.InitObstacle
function SendInitObstacle(Message)
    return _Send(Actions.InitObstacle, Message)
end

---@class Net.GetMixingId

---@param Message Net.GetMixingId
function SendGetMixingId(Message)
    return _Send(Actions.GetMixingId, Message)
end

---@class Net.GetSoundCueValue

---@param Message Net.GetSoundCueValue
function SendGetSoundCueValue(Message)
    return _Send(Actions.GetSoundCueValue, Message)
end

---@class Net.HasDisplayName

---@param Message Net.HasDisplayName
function SendHasDisplayName(Message)
    return _Send(Actions.HasDisplayName, Message)
end

---@class Net.GetDisplayName

---@param Message Net.GetDisplayName
function SendGetDisplayName(Message)
    return _Send(Actions.GetDisplayName, Message)
end

---@class Net.GetWeaponChargeFraction

---@param Message Net.GetWeaponChargeFraction
function SendGetWeaponChargeFraction(Message)
    return _Send(Actions.GetWeaponChargeFraction, Message)
end

---@class Net.GetAvgFps

---@param Message Net.GetAvgFps
function SendGetAvgFps(Message)
    return _Send(Actions.GetAvgFps, Message)
end

---@class Net.ProfileZoneStart

---@param Message Net.ProfileZoneStart
function SendProfileZoneStart(Message)
    return _Send(Actions.ProfileZoneStart, Message)
end

---@class Net.ProfileZoneEnd

---@param Message Net.ProfileZoneEnd
function SendProfileZoneEnd(Message)
    return _Send(Actions.ProfileZoneEnd, Message)
end

---@class Net.SendSaveFileEmail

---@param Message Net.SendSaveFileEmail
function SendSendSaveFileEmail(Message)
    return _Send(Actions.SendSaveFileEmail, Message)
end

