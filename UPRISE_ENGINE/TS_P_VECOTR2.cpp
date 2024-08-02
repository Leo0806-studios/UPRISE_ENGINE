#include "pch.h"
#include "TS_P_VECOTR2.h"

TS_P_Vector2::TS_P_Vector2() :x(0), y(0), pad1(0), pad2(0)
{
}

TS_P_Vector2::TS_P_Vector2(float x, float y):x(x),y(y),pad1(0),pad2(0)
{
}



TS_P_Vector2::operator __m128() const
{
  //TrPr(ctx, __func__)(TracyCZoneCtx ctx)
    return _mm_setr_ps(x, y, pad1, pad2);
}

float TS_P_Vector2::magnitude()
{
    __m128 val = _mm_setr_ps(x, y, pad1, pad2);
    return _mm_cvtss_f32(_mm_sqrt_ps(_mm_hadd_ps(_mm_mul_ps(val, val), _mm_setzero_ps())));
}

TS_P_Vector2 TS_P_Vector2::Normalized()
{
    return TS_P_Vector2();
}

float TS_P_Vector2::point(TS_P_Vector2 a)
{
    return 0.0f;
}

TS_P_Vector2 TS_P_Vector2::operator/(const float b)
{
    TrPr(ctx,__func__)
    TS_P_Vector2 _tmp;
    __m128 val = _mm_setr_ps(x, y, pad1, pad2);

    _mm_store_ps(&_tmp.x, _mm_div_ps(val, _mm_set_ps1(b)));
    TrPrE(ctx)
    return _tmp;;
}

TS_P_Vector2 TS_P_Vector2::operator/(const TS_P_Vector2 b)
{
    TrPr(ctx, __func__)

    TS_P_Vector2 _tmp;
    __m128 val = _mm_setr_ps(x, y, pad1, pad2);
    __m128 val1 = _mm_setr_ps(b.x, b.y, b.pad1, b.pad2);

    _mm_store_ps(&_tmp.x, _mm_div_ps(val, val1));

    TrPrE(ctx)
        return _tmp;
}

TS_P_Vector2 TS_P_Vector2::operator*(const float b)
{

    TrPr(ctx, __func__)
        TS_P_Vector2 _tmp;
    __m128 val = _mm_setr_ps(x, y, pad1, pad2);

    _mm_store_ps(&_tmp.x, _mm_mul_ps(val, _mm_set_ps1(b)));

    TrPrE(ctx)
        return _tmp;
}

TS_P_Vector2 TS_P_Vector2::operator*(const TS_P_Vector2 b)
{

    TrPr(ctx, __func__)
        TS_P_Vector2 _tmp;
    __m128 val = _mm_setr_ps(x, y, pad1, pad2);
    __m128 val1 = _mm_setr_ps(b.x, b.y, b.pad1, b.pad2);

    _mm_store_ps(&_tmp.x, _mm_mul_ps(val, val1));

    TrPrE(ctx)
        return _tmp;
}

TS_P_Vector2 TS_P_Vector2::operator-(const TS_P_Vector2 b)
{
    TrPr(ctx, __func__)
        __m128 val = _mm_setr_ps(x, y, pad1, pad2);

    __m128 val1 = _mm_setr_ps(b.x, b.y, b.pad1, b.pad2);
    TS_P_Vector2 _tmp;
    _mm_store_ps(&_tmp.x, _mm_sub_ps(val, val1));

    TrPrE(ctx)
        return _tmp;
}

TS_P_Vector2 TS_P_Vector2::operator+(const TS_P_Vector2 b)
{
    TrPr(ctx, __func__)
        TS_P_Vector2 tmp;
    __m128 this3 = _mm_setr_ps(x, y, pad1, pad2);
    __m128 be = _mm_setr_ps(b.x, b.y, b.pad1, b.pad2);
    _mm_store_ps(&tmp.x, _mm_add_ps(this3, be));

    TrPrE(ctx)
        return tmp;
}
