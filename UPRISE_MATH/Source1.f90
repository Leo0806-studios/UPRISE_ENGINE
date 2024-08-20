! mathlib.f90
module mathlib
 use, intrinsic :: iso_c_binding
  implicit none
contains

  function dot_product(a, b, n) result(dp) bind(C, name="dot_product")
    integer, intent(in) :: n
    real, intent(in) :: a(n), b(n)
    real :: dp
    integer :: i

    dp = 0.0
    do i = 1, n
      dp = dp + a(i) * b(i)
    end do
  end function dot_product

  function cross_product(a, b) result(c)
    real, intent(in) :: a(3), b(3)
    real :: c(3)

    c(1) = a(2) * b(3) - a(3) * b(2)
    c(2) = a(3) * b(1) - a(1) * b(3)
    c(3) = a(1) * b(2) - a(2) * b(1)
  end function cross_product

  function matrix_multiply(a, b, m, n, p) result(c)
    integer, intent(in) :: m, n, p
    real, intent(in) :: a(m, n), b(n, p)
    real :: c(m, p)
    integer :: i, j, k

    c = 0.0
    do i = 1, m
      do j = 1, p
        do k = 1, n
          c(i, j) = c(i, j) + a(i, k) * b(k, j)
        end do
      end do
    end do
  end function matrix_multiply

end module mathlib