/*
 *  elemental-ircd: A slightly useful ircd.
 *  attributes.h: Preprocessor macros for compiler attributes
 *
 *  Copyright (C) 2015 elemental-ircd development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 *  USA
 *
 */

#ifndef RB_ATTRIB_H
#define RB_ATTRIB_H 1

/* for GCC version checks, evaluates to zero if we're not on gcc */
#ifndef GCC_VERSION
#define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
#endif

/* Optimize for true or false branches */
#define rb_likely(x)       __builtin_expect(!!(x), 1)
#define rb_unlikely(x)     __builtin_expect(!!(x), 0)

/* Warn on unchecked returns */
#ifndef __must_check
#define __must_check    __attribute__((warn_unused_result))
#endif

/* Function never returns */
#ifndef __noreturn
#define __noreturn       __attribute__((noreturn))
#endif

/* Validate and Type-check printf arguments */
#ifndef __format_printf
#define __format_printf(fmt, args) __attribute__((format(printf, fmt, args)));
#endif

/* Mark argument as unused */
#ifndef __unused
#define __unused __attribute__((unused))
#endif

/* Mark a function as depricated */
#ifndef __deprecated
#define __deprecated __attribute__((deprecated))
#endif

/* Non-null return value */
#if     !defined(__returns_nonnull) && GCC_VERSION >= 4009
#define __returns_nonnull __attribute__((returns_nonnull))
#endif

#ifndef __returns_nonnull
#define __returns_nonnull
#endif

/* function returns new memory (and warn on unchecked return) */
#ifndef __malloc
#define __malloc __attribute__((malloc)) __must_check
#endif

#endif /* RB_ATTRIB_H */
