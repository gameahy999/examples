#ifndef __TRIVIAL_TEMPLATE_H__
#define __TRIVIAL_TEMPLATE_H__

/*
 * ‘double’ is not a valid type for a template non-type parameter
 * template<double VAT>
 * double process(double v) {
 *     return v * VAT;
 * }
 */

void test_nonTypeTemplateParameter();

#endif
